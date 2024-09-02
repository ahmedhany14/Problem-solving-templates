class combinatorics {
    ll mod = 998244353;
    vector<ll> factorial, inv, fact_inv;

    combinatorics(int sz) {
        factorial.resize(sz + 1);
        inv.resize(sz + 1);
        fact_inv.resize(sz + 1);

        factorial[0] = inv[0] = inv[1] = fact_inv[0] = fact_inv[1] = 1;

        for (ll i = 1; i <= sz; ++i) {
            factorial[i] = factorial[i - 1] * i % mod;
        }
        for (ll i = 2; i <= sz; ++i) {
            inv[i] = mod - mod / i * inv[mod % i] % mod;
        }
        for (ll i = 2; i <= sz; ++i) {
            fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
        }
    }

    ll nCk(ll n,ll k) {
        if (n < 0 || k > n || k < 0)return 0;
        return (factorial[n] * fact_inv[k] % mod * fact_inv[n - k] % mod);
    }

    ll nPk(ll n,ll k) {
        if (n < 0 || k > n || k < 0)return 0;
        return factorial[n] * fact_inv[n - k] % mod;
    }

    ll binmod(ll a,ll b) {
        a %= mod;
        ll s = 1;
        while (b) {
            if (b % 2 == 1)s = s * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return s;
    }


    ll mul(ll x, ll y) {
        x %= mod;
        y %= mod;
        return (x * 1ll * y) % mod;
    }

    ll add(ll x, ll y) {
        ll z = x + y;
        if (z >= mod) z -= mod;
        return z;
    }

    ll sub(ll x, ll y) {
        int z = x - y;
        if (z < 0) z += mod;
        return z;
    }

    ll inv_mod(ll x) { return binmod(x, mod - 2); }
    ll Div(ll x, ll y) { return mul(x, inv_mod(y)); }

    ll catalan(ll n) {
        return (nCk(2 * n, n) * inv_mod(n + 1)) % mod;
    }

    ll StarsAndPars(ll n,ll k) {
        return nCk(n + k - 1, k - 1);
    }
};
