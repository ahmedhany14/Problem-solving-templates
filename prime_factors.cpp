vector<ll>prime_factors(ll n) {
  vector<ll>pf;
  for (int i = 2; i <= n / i; i++) while (n % i == 0) pf.push_back(i), n /= i;
  if (n != 1) pf.push_back(n);
  return pf;
}
