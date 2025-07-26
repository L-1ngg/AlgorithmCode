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

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<Z> f(m + 1);
    std::map<int, std::vector<a3>> mp;
    Z base = 1;
    for (int i = 1;i <= n;i++) {
        int u, v, p, q; std::cin >> u >> v >> p >> q;
        mp[u].push_back({ v,p,q });
        base *= (((Z)q - (Z)p) / (Z)q);
    }
    f[0] = 1;
    for (int i = 1;i <= m;i++) {
        for (auto [j, p, q] : mp[i])
            f[j] += (f[i - 1] * ((Z)p / (Z)q) / (((Z)q - (Z)p) / (Z)q));
    }
    std::cout << f[m] * base << '\n';
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