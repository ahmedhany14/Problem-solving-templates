int const maxn = 1e6 + 10;
bitset<maxn>is_prime;
vector < ll > spf(maxn);
void sieve() {
  is_prime.set(); is_prime[0] = is_prime[1] = 0;
  for (ll i = 2; i <= maxn / i; i++)if (is_prime[i]) for (ll j = i * i; j < maxn; j += i) is_prime[j] = 0;
  for(int i = 1; i <= maxn; i++) spf[i] = i;
  spf[1] = OO;
  for(int i = 2; i <= maxn; i += 2) spf[i] = 2;
  for(int i = 3; i * i <= maxn; i++) if(spf[i] == i) for(int j = i * i; j <= maxn;j += i) if(spf[j] == j) spf[j] = i;
}
