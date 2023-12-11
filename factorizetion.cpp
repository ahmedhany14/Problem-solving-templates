set<ll>factors(ll n) {
  set<ll>fa;
  for (int i = 2; i <= n / i; i++)if (n % i == 0)fa.insert(i) ,fa.insert(n / i);
  return fa;
}
