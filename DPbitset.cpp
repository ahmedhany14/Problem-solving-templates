  bitset<N> dp(0);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    dp |= (dp << v[i]);
  }
