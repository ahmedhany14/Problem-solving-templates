ll maxsubarray(vc <ll> v) {
  ll sum = -1e9, best = -1e9;
  for (int i = 0; i < v.size(); i++)sum = max(v[i], sum + v[i]),best = max(best, sum);
  return best;
}
