const ll N = 2e6 + 5, inv_mod = 998244353; // 1e9 + 7

ll fact[N], inv_fact[N];

ll mul(const ll &a, const ll &b) { return (a % inv_mod + inv_mod) * (b % inv_mod + inv_mod) % inv_mod; }

ll binpow(ll a, ll b) {
    a %= inv_mod;
    ll res = 1;
    while (b > 0)(b & 1 ? res = res * a % inv_mod : res), a = a * a % inv_mod, b >>= 1;
    return res;
}

ll C(ll n, ll r) { return r > n ? 0 : mul(mul(fact[n], inv_fact[n - r]), inv_fact[r]); }

void build() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
    inv_fact[N - 1] = binpow(fact[N - 1], inv_mod - 2);
    for (int i = N - 2; ~i; --i) inv_fact[i] = mul(inv_fact[i + 1], i + 1);
}
