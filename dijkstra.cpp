int n;
const int maxn = 2e5;
priority_queue<pair<ll,int>,vc<pair<ll,int>>,greater<pair<ll,int>> >pq;
vector<pair<int,ll>>g[maxn];
ll dist [maxn],path[maxn];
void clear(int n){
  for(int i = 0 ; i <= n ;i++)
    dist[i] = 1e9 , path[i] = -1;
}
void dijkstra(int source) {
  dist[source] = 0;
  pq.emplace(0, source);
  while (pq.size()) {
    auto [cost, patent] = pq.top();
    pq.pop();
    if (cost > dist[patent])
      continue;
    for (auto &[child, wight] : g[patent]) {
      ll newWight = wight + cost;
      if (dist[child] > newWight) {
        path[child] = patent;
        dist[child] = newWight;
        pq.emplace(dist[child], child);
      }
    }
  }
}
void bulid(int e) {
  if (!~path[e])
    return;
  bulid(path[e]);
  cout << e << " ";
}
