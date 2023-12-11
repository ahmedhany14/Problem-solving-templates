  auto can = [&](ll m)->ll{
    
  };
  ll l = 0, r = 1e9;
  for (int i = 0; i < 200; i++) {
    ll m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
    if (can(m1) > can(m2)) l = m1;
    else r = m2;
  }
  cout << can((l + r) / 2) << endl;
