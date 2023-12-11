void subset(ll n) {
  vector<int>vec(n), sub;
  for (auto& it : vec)cin >> it;
  for (int mask = 0; mask < (1 << n); mask++) {
    sub.clear();
    for (int i = 0; i < n; i++)if (mask & (1 << i))sub.push_back(vec[i]);
    for (auto& it : sub)cout << it << " ";
    if (!sub.empty())cout << endl;
  }
}
