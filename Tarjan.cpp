class Tarjan {
public:
    Tarjan(int n) {
        init(n);
    }

    void addEdge(int u, int v, bool is_directed = false) {
        graph[u].push_back(v);
        if (!is_directed)
            graph[v].push_back(u); // Assuming an undirected graph
    }

    void run() {
        for (int i = 0; i < graph.size(); ++i) {
            if (node_idx[i] == -1) {
                dfs(i);
            }
        }
    }

    set<int> getArticulationPoints() {
        return art_points;
    }

    vector<pair<int, int> > getBridges() {
        return bridges;
    }

    bool isArticulationPoint(int u) {
        return art_points.find(u) != art_points.end();
    }

    bool isBridge(int u, int v) {
        return find(bridges.begin(), bridges.end(), make_pair(u, v)) != bridges.end() ||
               find(bridges.begin(), bridges.end(), make_pair(v, u)) != bridges.end();
    }

    int get_children(int u) {
        return children[u];
    }

private:
    int timer;
    vector<vector<int> > graph, comps;
    vector<int> low_link, node_idx, comp_idx;
    vector<bool> in_stack;
    stack<int> stk;
    vector<pair<int, int> > bridges;
    set<int> art_points;

    vector<int> children;
    vector<bool> visited;

    void init(int n) {
        timer = 0;
        graph.assign(n + 5, vector<int>());
        low_link.assign(n + 5, -1);
        node_idx.assign(n + 5, -1);
        comp_idx.assign(n + 5, -1);
        in_stack.assign(n + 5, false);
        comps.clear();
        while (!stk.empty()) stk.pop();

        children.assign(n + 5, 0);
        visited.assign(n + 5, false);
    }

    void dfs(int node, int parent = -1) {
        low_link[node] = node_idx[node] = timer++;
        in_stack[node] = true;
        stk.push(node);

        visited[node] = true;
        children[node] = 1;

        int childrens = 0;

        for (int child: graph[node]) {
            if (child == parent) continue; // Ignore the edge to parent in undirected graph
            if (node_idx[child] == -1) {
                // If v is not visited
                dfs(child, node);
                low_link[node] = min(low_link[node], low_link[child]);
                if (low_link[child] == node_idx[child])
                    bridges.emplace_back(node, child);
                if (parent != -1 && low_link[child] >= node_idx[node])
                    art_points.insert(node);
                children[node] += children[child];
                ++childrens;
            } else if (in_stack[child]) {
                low_link[node] = min(low_link[node], node_idx[child]);
            }
        }

        if (parent == -1 && childrens > 1)
            art_points.insert(node);

        if (low_link[node] == node_idx[node]) {
            comps.emplace_back();
            int v;
            do {
                v = stk.top();
                stk.pop();
                in_stack[v] = false;
                comps.back().push_back(v);
                comp_idx[v] = comps.size() - 1;
            } while (v != node);
        }
    }
};
