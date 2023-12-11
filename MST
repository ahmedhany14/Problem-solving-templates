const int maxn = 30;
vc<pair<int,ll>>g[maxn];
bool vis[maxn];
void dfs(int node){
  vis[node] = 1;
  for(auto [c , w] : g[node]){
    if(!vis[c])
      dfs(c);
  }
}
ll MST (int source){
  ::memset(vis , 0 ,sizeof vis);
  set<pair<int, int>>st;
  long long sum = 0;
  st.insert({ 0,source });
  while (!st.empty()) {
    auto [edge ,node] = *st.begin();
    st.erase(st.find(*st.begin()));
    if (!vis[node]) {
      sum += edge;
      for(auto [c , w] : g[node]){
        if (!vis[c] && c != node) st.insert({ w, c });
      }
    }
    vis[node] = 1;
  }
  return sum;
}
