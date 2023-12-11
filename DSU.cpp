template < typename T = int > struct DSU {
  vc<T> groupSize, parent, rank, mx, mn;
  DSU(int n = 1e5 + 10) {
    groupSize.resize(n + 1);
    parent.resize(n + 1);
    rank.resize(n + 1);
    mx.resize(n + 1);
    mn.resize(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i, mx[i] = mn[i] = i, groupSize[i] = 1, rank[i] = 0;
  }
  void make_set(int u) {
    parent[u] = u;
    groupSize[u] = 1;
  }
  int find_set(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find_set(parent[x]);
  }
  void union_set(int u, int v) {
    int leader1 = find_set(u);
    int leader2 = find_set(v);
    if (leader1 == leader2)
      return;
    if (groupSize[leader1] < groupSize[leader2])
      swap(leader1, leader2);
    parent[leader2] = leader1;
    groupSize[leader1] += groupSize[leader2];
    if (rank[leader1] == rank[leader2])
      rank[leader1]++;

    mx[leader1] = max(mx[leader1], mx[leader2]);
    mn[leader1] = min(mn[leader1], mn[leader2]);
  }
  bool samegroup(int u, int v) {
    int lead1 = find_set(u), lead2 = find_set(v);
    return lead1 == lead2;
  }
  int sizeGroup(int u) {
    int lead = find_set(u);
    return groupSize[lead];
  }
  int get_max(int u) { return mx[find_set(u)]; }
  int get_min(int u) { return mn[find_set(u)]; }
};
