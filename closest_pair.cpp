ll closest_pair(vector<pair<int, int>> pointes) {
  int n = pointes.size();
  sort(pointes.begin(), pointes.end());
  set<pair<int, int>> st;
  ll bestDist = 1e18;
  int j = 0;
  for (int idx = 0; idx < n; ++idx) {
    int d = ceil(sqrt(bestDist));
    while (pointes[idx].first - pointes[j].first >= d) st.erase({ pointes[j].second, pointes[j].first }), ++j;
    auto a = st.lower_bound({ pointes[idx].second - d, pointes[idx].first });
    auto aa = st.upper_bound({ pointes[idx].second + d, pointes[idx].first });
    for (auto start = a; start != aa; ++start) {
      int dx = pointes[idx].first - start->second;
      int dy = pointes[idx].second - start->first;
      bestDist = min(bestDist, 1LL * dx * dx + 1LL * dy * dy);
    }
    st.insert({ pointes[idx].second, pointes[idx].first });
  }
  return bestDist;
}
