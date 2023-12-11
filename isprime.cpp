bool isprime(ll x) {
  if (x < 2) return 0;
  for (int i = 2; i <= x / i; i++) if (x % i == 0) return 0;
  return x > 1;
}
