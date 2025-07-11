#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 2005;
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

template<typename T>
struct Comb {
    std::vector<T> fac;
    std::vector<T> facInv;
    int n;

    Comb(int n_) {
        n = n_;
        fac.assign(n, T{});
        facInv.assign(n, T{});
        fac[0] = 1;
        for (int i = 1; i < n; i++) {
            fac[i] = fac[i - 1] * i;
        }
        for (int i = 0; i < n; i++) {
            facInv[i] = fac[i].inv();
        }
    }
};

Comb<Z> comb(COMB_N);

template<std::signed_integral T>
Z P(T n, T m) {
    if (n < 0 || m < 0 || n < m) throw "n<0,m<0,n<m";
    if (n < comb.n) {
        return comb.fac[n] * comb.facInv[n - m];
    }
    else {
        T v = n, rnd = m;
        Z res = 1;
        while (rnd--) {
            res *= v--;
        }
        return res;
    }
}

template<std::signed_integral T>
Z C(T n, T m) {
    return P(n, m) * comb.facInv[m];
}

int a[N];
int f[N][N];
void solve()
{
    int m, d;   std::cin >> m >> d;
    std::string s1, s2;   std::cin >> s1 >> s2;

    int len;
    auto dfs = [&](auto&& self, bool limit, int pos, int r)->Z {
        if (!pos) return (r == 0 ? 1 : 0);
        if (!limit && ~f[pos][r])   return f[pos][r];

        int up = limit ? a[pos] : 9;
        Z res = 0;

        int p = len + 1 - pos;
        if (p & 1)
            for (int i = 0; i <= up;i++) {
                if (i == d) continue;
                res += self(self, limit && i == up, pos - 1, (r * 10 + i) % m);
            }
        else { if (d <= up) res += self(self, limit && d == up, pos - 1, (r * 10 + d) % m); }

        if (!limit) f[pos][r] = res.val();
        return res;
        };

    //12345678789
    auto op = [&](std::string s) ->Z {
        len = 0;
        for (int i = 0; i < s.length();i++) a[++len] = s[s.length() - i - 1] - '0';
        return dfs(dfs, 1, len, 0);
        };

    auto check = [&](std::string s) ->Z {
        len = 0;
        for (int i = 0; i < s.length();i++) a[++len] = s[s.length() - i - 1] - '0';

        int r = 0;
        for (int i = len;i >= 1;i--) {
            int p = len - i + 1;
            if (p & 1) { if (a[i] == d) return 0; }
            else { if (a[i] != d) return 0; }
            r = (r * 10 + a[i]) % m;
        }
        return (r == 0 ? 1 : 0);
        };

    memset(f, -1, sizeof f);
    std::cout << op(s2) - op(s1) + check(s1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}