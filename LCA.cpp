template < typename T = int > struct LCA {

  int maxn, LOG;
  vc < vc < T > > up;
  vc < vc < T > > g;
  vc < int > depth, parent;
  vc< bool > vis;
  LCA(int n = 1e5){
    maxn = n + 10, LOG = 0;
    while((1 << LOG) <= n) LOG++;
    depth =  parent = vc < int > (maxn);
    vis = vc < bool > (maxn);
    g = vc < vc < T > > (maxn);
    up = vc < vc < T > > (maxn, vc < T > (LOG));
  }

  LCA(int n, const vc < vc < T > > &G, const vc < T >& P) : g(G), parent(P) {
    maxn = n + 10, LOG = 0;
    while((1 << LOG) <= n) LOG++;
    depth = vc < int > (maxn);
    vis = vc < bool > (maxn);
    up = vc < vc < T > > (maxn, vc < T > (LOG));
  }

  void add_edge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
  }

  void build_adj(int edges){
    for(int i = 0, u, v; i < edges && cin >> u >> v; i++)
      add_edge(u, v);
  }

  void dfs(int u, int p = 0){
    vis[u] = 1;
    for(auto& v : g[u]){
      if(vis[v]) continue;

      depth[v] = depth[u] + 1, up[v][0] = u;

      for(int bit = 1; bit < LOG; bit++)
        up[v][bit] = up[up[v][bit - 1]][bit - 1];

      dfs(v, u);
    }
  }

  int kth_ancestor(int u, int k){
    if(depth[u] < k) return -1;

    for(int bit = LOG - 1; bit >= 0; bit--)
      if(k & (1 << bit))
        u = up[u][bit];

    return u;
  }

  int get_lca(int u, int v){
    if(depth[u] < depth[v])
      swap(u, v);

    u = kth_ancestor(u, depth[u] - depth[v]);

    if(u == v) return u;

    for(int bit = LOG - 1; bit >= 0; bit--)
      if(up[u][bit] != up[v][bit])
        u = up[u][bit], v = up[v][bit];

    return up[u][0];
  }

  T query(int u, int v){
    int lca = get_lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
  }

  void build(int n){
    for(int i = 1; i <= n; i++)
      if(parent[i] == 0)
        dfs(i);
  }
};
