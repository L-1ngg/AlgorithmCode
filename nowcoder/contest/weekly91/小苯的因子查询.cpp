#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;



constexpr int M = 998244353;
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

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<int> primes;
std::vector<int> minp(N + 1);
std::vector<Z> total(N + 1), odd(N + 1), d(N + 1);

void init() {
    for (int i = 2; i <= N;i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto pri : primes) {
            if (i * pri > N) break;
            minp[i * pri] = pri;
            if (pri == minp[i]) break;
        }
    }

    total[0] = odd[0] = 1;
    for (int i = 1;i <= N;i++) {
        int j = i;
        std::vector<pii> vec;
        while (j > 1) {
            int p = minp[j];
            int c = 0;
            while (j % p == 0) j /= p, c++;
            vec.push_back({ p,c });
        }
        total[i] = total[i - 1];
        odd[i] = odd[i - 1];
        for (auto [x, y] : vec) {
            total[i] /= (d[x] + 1);
            if (x > 2)odd[i] /= (d[x] + 1);
            d[x] += y;
            total[i] *= (d[x] + 1);
            if (x > 2)odd[i] *= (d[x] + 1);
        }
    }
}

void solve()
{
    int x;  std::cin >> x;
    std::cout << odd[x] / total[x] << " ";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();
    int t;
    std::cin >> t;
    while (t--)
        solve();
}