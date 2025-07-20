#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

template<class T> constexpr T qpow(T n, i64 k) {
    T r = 1;
    for (; k; k /= 2, n *= n) {
        if (k % 2) {
            r *= n;
        }
    }
    return r;
}

template<class T> constexpr T power(int n) {
    return qpow(T(2), n);
}

template<const int& MOD> struct Zmod {
    int x;
    Zmod(signed x = 0) : x(norm(x% MOD)) {}
    Zmod(i64 x) : x(norm(x% MOD)) {}

    constexpr int norm(int x) const noexcept {
        if (x < 0) [[unlikely]] {
            x += MOD;
        }
        if (x >= MOD) [[unlikely]] {
            x -= MOD;
        }
        return x;
    }
    explicit operator int() const {
        return x;
    }
    constexpr int val() const {
        return x;
    }
    constexpr Zmod operator-() const {
        Zmod val = norm(MOD - x);
        return val;
    }
    constexpr Zmod inv() const {
        assert(x != 0);
        return qpow(*this, MOD - 2);
    }
    friend constexpr auto& operator>>(std::istream& in, Zmod& j) {
        int v;
        in >> v;
        j = Zmod(v);
        return in;
    }
    friend constexpr auto& operator<<(std::ostream& o, const Zmod& j) {
        return o << j.val();
    }
    constexpr Zmod& operator++() {
        x = norm(x + 1);
        return *this;
    }
    constexpr Zmod& operator--() {
        x = norm(x - 1);
        return *this;
    }
    constexpr Zmod operator++(signed) {
        Zmod res = *this;
        ++*this;
        return res;
    }
    constexpr Zmod operator--(signed) {
        Zmod res = *this;
        --*this;
        return res;
    }
    constexpr Zmod& operator+=(const Zmod& i) {
        x = norm(x + i.x);
        return *this;
    }
    constexpr Zmod& operator-=(const Zmod& i) {
        x = norm(x - i.x);
        return *this;
    }
    constexpr Zmod& operator*=(const Zmod& i) {
        x = i64(x) * i.x % MOD;
        return *this;
    }
    constexpr Zmod& operator/=(const Zmod& i) {
        return *this *= i.inv();
    }
    constexpr Zmod& operator%=(const int& i) {
        return x %= i, *this;
    }
    friend constexpr Zmod operator+(const Zmod i, const Zmod j) {
        return Zmod(i) += j;
    }
    friend constexpr Zmod operator-(const Zmod i, const Zmod j) {
        return Zmod(i) -= j;
    }
    friend constexpr Zmod operator*(const Zmod i, const Zmod j) {
        return Zmod(i) *= j;
    }
    friend constexpr Zmod operator/(const Zmod i, const Zmod j) {
        return Zmod(i) /= j;
    }
    friend constexpr Zmod operator%(const Zmod i, const int j) {
        return Zmod(i) %= j;
    }
    friend constexpr bool operator==(const Zmod i, const Zmod j) {
        return i.val() == j.val();
    }
    friend constexpr bool operator!=(const Zmod i, const Zmod j) {
        return i.val() != j.val();
    }
    friend constexpr bool operator<(const Zmod i, const Zmod j) {
        return i.val() < j.val();
    }
    friend constexpr bool operator>(const Zmod i, const Zmod j) {
        return i.val() > j.val();
    }
};

int MOD[] = { 998244353, 1000000007 };
using Z = Zmod<MOD[0]>;

struct Comb {
    int n;
    std::vector<Z> _fac, _inv;

    Comb() : _fac{ 1 }, _inv{ 0 } {}
    Comb(int n) : Comb() {
        init(n);
    }
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _inv[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _inv[i - 1] = _inv[i] * i;
        }
        n = m;
    }
    Z fac(int x) {
        if (x > n) init(x);
        return _fac[x];
    }
    Z inv(int x) {
        if (x > n) init(x);
        return _inv[x];
    }
    Z C(int x, int y) {
        if (x < 0 || y < 0 || x < y) return 0;
        return fac(x) * inv(y) * inv(x - y);
    }
    Z P(int x, int y) {
        if (x < 0 || y < 0 || x < y) return 0;
        return fac(x) * inv(x - y);
    }
} comb(1 << 21);


void solve()
{
    int n;  std::cin >> n;
    std::map<int, int> mp;
    std::vector<std::vector<int>> a(n + 1);
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        a[i].assign(x + 1, 0);
        a[i][0] = x;
        for (int j = 1;j <= x;j++) {
            std::cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }

    Z ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= a[i][0];j++) {
            ans += Z(a[i][0]).inv() * Z(n).inv() * Z(mp[a[i][j]]) * Z(n).inv();
        }
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}