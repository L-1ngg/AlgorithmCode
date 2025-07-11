#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#if !defined(ONLINE_JUDGE) && defined(LOCAL)
#include "helper.h"
#else
#define dbg(...) ;
#define local_go_m(x) int c;cin>>c;while(c--)x()
#endif

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

struct Sieve {
    vector<bool> isp;
    vector<int> primes;
    int top;

    Sieve(int top_ = 300300) {
        top = top_ + 1;
        isp.assign(top, true);
        isp[1] = false;
        for (int i = 2; i < top; ++i) {
            if (isp[i]) {
                primes.push_back(i);
            }
            // Euler sieve method O(n).
            for (int p : primes) {
                if (i * p >= top)
                    break;
                isp[i * p] = false;
                if (i % p == 0)
                    break;
            }
        }
    }

    map<int, int> factorization(int v) {
        map<int, int> res;
        for (int p : primes) {
            if (v == 1)
                break;
            if (i64(p) * p > v)
                break;
            int cnt = 0;
            while (v % p == 0) {
                cnt++;
                v /= p;
            }
            if (cnt) {
                res[p] = cnt;
            }
        }
        if (v > 1)
            res[v] = 1; // final large prime.
        return res;
    }

    vector<int> divisors(int v) {
        map<int, int> f = factorization(v);
        vector<int> res;
        res.push_back(1);
        for (auto [p, c] : f) {
            int t = res.size(), x = 1;
            for (int i = 0; i < c; ++i) {
                x *= p;
                for (int j = 0; j < t; ++j)
                    res.push_back(res[j] * x);
            }
        }
        return res;
    }

    bool isPrime(int v) {
        if (v < top)
            return isp[v];
        assert(i64(top - 1) * (top - 1) >= v);
        for (int p : primes)
            if (v % p == 0)
                return false;
        return true;
    }
};

// 31622.7^2=10^9
// when top is 32000, primes.length=3432.
// 10^5 decomp() call on 10^9-size-value is affordable.
// 2*3*5*7*11*13*17*19*23 = 223_092_870, 9 diff prime factors.
// 2*2*3*3*5*5*7*7*11*11*13*13 = 901_800_900, 729 divisors.
// count of divisors: (approximate n^(1/3))
// <2^31 : 2095133040 1600, 1745944200 1536, 1396755360 1536, 1837836000 1536
//         1862340480 1536, 2058376320 1536, 1470268800 1536, 1715313600 1512
// <10^9 : 931170240 1344, 735134400 1344, 857656800 1296, 980179200 1296
//         698377680 1280, 918918000 1280, 882161280 1280, 908107200 1260
// <10^6 : 720720 240, 831600 240, 997920 240, 960960 224, 665280 224
Sieve sieve(1000100);

void go() {
    int K, n;
    cin >> K >> n;
    cout << n << " "; // x==1 case.
    vector<int> a(100);
    for (int x = 2; x <= K; x++) {
        Z res = 0;
        vector<int> ds = sieve.divisors(x);
        ranges::sort(ds);
        int cur = x;
        auto dfs = [&](this auto&& self, int t = 0) -> void { // NOLINT(*-no-recursion)
            if (t) {
                if (cur == 1) {
                    if (t > n) return;
                    Z r1 = P(t, t);
                    for (int i = 0; i < t;) {
                        int ei = i + 1;
                        while (ei < t && a[i] == a[ei]) ei++;
                        r1 /= P(ei - i, ei - i);
                        i = ei;
                    }
                    r1 *= C(n + 1, t + 1);
                    res += r1;
                    return;
                }
                if (cur < ds[a[t - 1]]) return;
            }
            for (int i = t ? a[t - 1] : 1; i < ds.size(); i++) {
                if (cur % ds[i] != 0) continue;
                a[t] = i;
                cur /= ds[i];
                self(t + 1);
                cur *= ds[i];
            }
            };
        dfs();
        cout << res << " ";
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    local_go_m(go);
    return 0;
}