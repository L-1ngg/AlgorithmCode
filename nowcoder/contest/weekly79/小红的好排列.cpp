#include <bits/stdc++.h>


#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using namespace std;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

struct Comb {
    const int P = 13331;
    i64 qmi(i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1)
                ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    };
    void init(int M) {
        fac.resize(M + 10, 1);
        inv.resize(M + 10, 1);
        finv.resize(M + 10, 1);
        for (int i = 2; i <= M; i++)
            fac[i] = fac[i - 1] * i % mod;
        finv[M] = qmi(fac[M], mod - 2);
        for (int i = M - 1;i >= 0;i--) {
            finv[i] = finv[i + 1] * (i + 1) % mod;
        }
        inv[1] = qmi(P, mod - 2);
        for (int i = 2; i <= M; i++) {
            inv[i] = inv[i - 1] * P % mod;

        }
    };
    i64 C(i64 n, i64 m) {
        assert(n >= 0 && m >= 0 && n <= m);
        if (n == 0 || m == 0)
            return 1ll;
        i64 c = fac[m - n] * fac[n] % mod;
        return fac[m] * finv[n] % mod * finv[m - n] % mod;
    };
    i64 A(int n, int m) { return fac[n] * C(n, m) % mod; }
    vector<i64> fac, inv, finv;
};

void solve()
{
    int n;
    std::cin >> n;
    if (n == 2)
    {
        std::cout << 0;
        return;
    }
    int num = n / 3, cnt0 = n / 2 - num;
    int ans = 1;

    Comb tmp;
    tmp.init(1e6);

    ans = (ans * tmp.C(n - num, cnt0)) % mod;
    ans = (ans * tmp.C(num, num - cnt0)) % mod;
    ans = (ans * tmp.A(n - num, n - num)) % mod;
    ans = (ans * tmp.A(num, num)) % mod;

    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}