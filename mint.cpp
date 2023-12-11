template<long long MOD = 1000000007>struct ModLongLong {
    long long val;
    ModLongLong(long long V = 0) :val(V) {
        val %= MOD;
    }
    ModLongLong& operator+=(const ModLongLong& change) {
        if ((val += change.val) >= MOD)val -= MOD;
        return *this;
    }
    ModLongLong& operator+=(const long long change) {
        if ((val += change) >= MOD)val -= MOD;
        return *this;
    }
    ModLongLong& operator-=(const ModLongLong& change) {
        if ((val += MOD - change.val) >= MOD)val -= MOD;
        return *this;
    }
    ModLongLong& operator-=(const long long change) {
        if ((val += MOD - change) >= MOD)val -= MOD;
        return *this;
    }
    ModLongLong& operator *= (const ModLongLong& change) {
        val = (1LL * (val % MOD) * (change.val % MOD)) % MOD;
        return *this;
    }
    ModLongLong& operator *= (const long long change) {
        val = (1LL * (val % MOD) * (change % MOD)) % MOD;
        return *this;
    }
    ModLongLong& operator /= (const ModLongLong& change) {
        return this = change.inverse();
    }
    ModLongLong& operator /= (const long long change) {
        return this = ModLongLong(change).inverse();
    }
    ModLongLong& operator %= (const ModLongLong& change) {
        val %= change.val;
        return *this;
    }
    ModLongLong& operator %= (const long long change) {
        val %= change;
        return *this;
    }
    ModLongLong& operator ++ () {
        return *this += 1;
    }
    ModLongLong& operator -- () {
        return *this -= 1;
    }
    ModLongLong operator ++ (int unused) {
        ModLongLong res(*this);
        ++* this;
        return res;
    }
    ModLongLong operator -- (int unused) {
        ModLongLong res(*this);
        --* this; return res;
    }
    ModLongLong operator + (const ModLongLong& change)const {
        ModLongLong res(*this);
        return res += change;
    }
    ModLongLong operator + (const long long change)const {
        ModLongLong res(*this);
        return res += change;
    }
    ModLongLong operator % (const ModLongLong& change)const {
        ModLongLong res(*this);
        return res %= change;
    }
    ModLongLong operator % (const long long change)const {
        ModLongLong res(*this);
        return res %= change;
    }
    ModLongLong operator - (const ModLongLong& change)const {
        ModLongLong res(*this);
        return res -= change;
    }
    ModLongLong operator - (const long long change)const {
        ModLongLong res(*this);
        return res -= change;
    }
    ModLongLong operator * (const ModLongLong& change)const {
        ModLongLong res(this);
        return res = change;
    }
    ModLongLong operator * (const long long change)const {
        ModLongLong res(this);
        return res = change;
    }
    ModLongLong operator / (const ModLongLong& change)const {
        ModLongLong res(*this);
        return res /= change;
    }
    ModLongLong operator / (const long long rhs)const {
        ModLongLong res(*this);
        return res /= rhs;
    }
    ModLongLong& operator = (const ModLongLong& change) {
        val = change.val;
        return *this;
    }
    ModLongLong& operator = (const long long change) {
        val = change;
        return *this;
    }
    bool operator == (const ModLongLong& change)const {
        return val == change.val;
    }
    bool operator == (const long long change)const {
        return val == change;
    }
    bool operator != (const ModLongLong& change)const {
        return val != change.val;
    }
    bool operator != (const long long change)const {
        return val != change;
    }
    bool operator < (const ModLongLong& change)const {
        return val < change.val;
    }
    bool operator < (const long long change)const {
        return val < change;
    }
    bool operator <= (const ModLongLong& change)const {
        return val <= change.val;
    }
    bool operator <= (const long long change)const {
        return val <= change;
    }
    bool operator > (const ModLongLong& change)const {
        return val > change.val;
    }
    bool operator > (const long long change)const {
        return val > change;
    }
    bool operator >= (const ModLongLong& change)const {
        return val >= change.val;
    }
    bool operator >= (const long long change)const {
        return val >= change;
    }
    int operator()()const {
        return val;
    }
    ModLongLong inverse()const {
        return power(MOD - 2);
    }
    ModLongLong power(long long n)const {
        ModLongLong a = *this, res = 1;
        while (n > 0) {
            if (n & 1)res *= a;
            a *= a, n >>= 1;
        }
        return res;
    }
    ModLongLong power(ModLongLong n)const {
        ModLongLong a = *this, res = 1;
        int e = n();
        while (e > 0) {
            if (e & 1)res *= a;
            a *= a, e >>= 1;
        }
        return res;
    }
    friend ModLongLong operator^(ModLongLong rhs, long long n) {
        return rhs.power(n);
    }
    friend ModLongLong operator^(ModLongLong rhs, ModLongLong n) {
        return rhs.power(n);
    }
    friend std::istream& operator>>(std::istream& is, ModLongLong& x)noexcept {
        return is >> x.val;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModLongLong& x)noexcept {
        return os << x.val;
    }
};
using Mint = ModLongLong<>;
