int const maxn = 200005;
ll fact[maxn] , inv_fact[maxn];
int const inv_mod = 998244353;
ll binpow(ll a,ll b) {
  a %= inv_mod;
  ll res = 1;
  while (b > 0)(b & 1 ? res = res * a % inv_mod : res), a = a * a % inv_mod, b >>= 1;
  return res;
}
ll inv_p(ll a) { return binpow(a, inv_mod - 2); }
ll C(ll n , ll k) { return fact[n] * inv_fact[n - k] % inv_mod * inv_fact[k]% inv_mod; }
void modify() {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++)fact[i] = fact[i - 1] * i % inv_mod, inv_fact[i] = inv_p(fact[i]);
}
