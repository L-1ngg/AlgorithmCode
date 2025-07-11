/*
#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

constexpr int M = 1e9 + 7;
constexpr int COMB_N = 300300;

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template<int M>
struct ModInt {
public:
    constexpr ModInt() : x(0) {}

    template<std::signed_integral T>
    constexpr ModInt(T x_) {
        T v = x_ % M;
        if (v < 0) {
            v += M;
        }
        x = v;
    }

    constexpr int val() const {
        return x;
    }

    constexpr ModInt operator-() const {
        ModInt res;
        res.x = (x == 0 ? 0 : M - x);
        return res;
    }

    constexpr ModInt inv() const {
        return power(*this, M - 2);
    }

    constexpr ModInt& operator*=(const ModInt& rhs)& {
        x = i64(x) * rhs.val() % M;
        return *this;
    }

    constexpr ModInt& operator+=(const ModInt& rhs)& {
        x += rhs.val();
        if (x >= M) {
            x -= M;
        }
        return *this;
    }

    constexpr ModInt& operator-=(const ModInt& rhs)& {
        x -= rhs.val();
        if (x < 0) {
            x += M;
        }
        return *this;
    }

    constexpr ModInt& operator/=(const ModInt& rhs)& {
        return *this *= rhs.inv();
    }

    friend constexpr ModInt operator*(ModInt lhs, const ModInt& rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModInt operator+(ModInt lhs, const ModInt& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModInt operator-(ModInt lhs, const ModInt& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModInt operator/(ModInt lhs, const ModInt& rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::istream& operator>>(std::istream& is, ModInt& a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const ModInt& a) {
        return os << a.val();
    }

    friend constexpr std::strong_ordering operator<=>(ModInt lhs, ModInt rhs) {
        return lhs.val() <=> rhs.val();
    }

private:
    int x;
};

using Z = ModInt<M>;


Z dp[1002][202][202][2];

void solve()
{
    int n, m, k;   std::cin >> n >> m >> k;
    std::string a, b;   std::cin >> a >> b;
    a = " " + a;
    b = " " + b;

    for (int i = 0; i <= n;i++) {
        dp[i][0][0][1] = 0;
        dp[i][0][0][0] = 1;
    }
    for (int i = 0; i <= m;i++) {
        dp[0][i][0][1] = 0;
        dp[0][i][0][0] = 0;
    }
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= std::min(i, m);j++)
            for (int p = 1; p <= k;p++)
            {
                if (a[i] == b[j]) {
                    dp[i][j][p][1] = dp[i - 1][j - 1][p][1] + dp[i - 1][j - 1][p - 1][1] + dp[i - 1][j - 1][p - 1][0];
                }
                else dp[i][j][p][1] = 0;
                dp[i][j][p][0] = dp[i - 1][j][p][1] + dp[i - 1][j][p][0];
            }
    std::cout << dp[n][m][k][1] + dp[n][m][k][0];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}

*/

#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

constexpr int M = 1e9 + 7;
constexpr int COMB_N = 300300;

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template<int M>
struct ModInt {
public:
    constexpr ModInt() : x(0) {}

    template<std::signed_integral T>
    constexpr ModInt(T x_) {
        T v = x_ % M;
        if (v < 0) {
            v += M;
        }
        x = v;
    }

    constexpr int val() const {
        return x;
    }

    constexpr ModInt operator-() const {
        ModInt res;
        res.x = (x == 0 ? 0 : M - x);
        return res;
    }

    constexpr ModInt inv() const {
        return power(*this, M - 2);
    }

    constexpr ModInt& operator*=(const ModInt& rhs)& {
        x = i64(x) * rhs.val() % M;
        return *this;
    }

    constexpr ModInt& operator+=(const ModInt& rhs)& {
        x += rhs.val();
        if (x >= M) {
            x -= M;
        }
        return *this;
    }

    constexpr ModInt& operator-=(const ModInt& rhs)& {
        x -= rhs.val();
        if (x < 0) {
            x += M;
        }
        return *this;
    }

    constexpr ModInt& operator/=(const ModInt& rhs)& {
        return *this *= rhs.inv();
    }

    friend constexpr ModInt operator*(ModInt lhs, const ModInt& rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModInt operator+(ModInt lhs, const ModInt& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModInt operator-(ModInt lhs, const ModInt& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModInt operator/(ModInt lhs, const ModInt& rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::istream& operator>>(std::istream& is, ModInt& a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const ModInt& a) {
        return os << a.val();
    }

    friend constexpr std::strong_ordering operator<=>(ModInt lhs, ModInt rhs) {
        return lhs.val() <=> rhs.val();
    }

private:
    int x;
};

using Z = ModInt<M>;


Z dp[3][202][202][2];

void solve()
{
    int n, m, k;   std::cin >> n >> m >> k;
    std::string a, b;   std::cin >> a >> b;
    a = " " + a;
    b = " " + b;

    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= std::min(i, m);j++)
            for (int p = 1; p <= k;p++)
            {
                if (a[i] == b[j]) {
                    dp[i % 2][j][p][1] = dp[(i - 1) % 2][j - 1][p][1] + dp[(i - 1) % 2][j - 1][p - 1][1] + dp[(i - 1) % 2][j - 1][p - 1][0];
                }
                else dp[i % 2][j][p][1] = 0;
                dp[i % 2][j][p][0] = dp[(i - 1) % 2][j][p][1] + dp[(i - 1) % 2][j][p][0];
            }
    std::cout << dp[n % 2][m][k][1] + dp[n % 2][m][k][0];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}