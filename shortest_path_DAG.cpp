const int maxn = 2e5 + 10;
ll dist [maxn];
bool vis[maxn];
stack<int>topo_sort;
vector<pair<int,ll>>g[maxn];
void clear(int n){
  for (int i = 0; i < maxn; i++)
    dist[i] = OO, vis[i] = 0, g[i].clear();
  while (topo_sort.size())
    topo_sort.pop();
}
void dfs(int source) {
  vis[source] = 1;
  for (auto ch : g[source])
    if (!vis[ch.first])
      dfs(ch.first);
  topo_sort.emplace(source);
}
void shortest_DAG(int source) {
  dist[source] = 0;
  while (topo_sort.size()) {
    int parant = topo_sort.top();
    topo_sort.pop();
    for (auto [child, cost] : g[parant])
      dist[child] = min(dist[child], dist[parant] + cost);
  }
}
