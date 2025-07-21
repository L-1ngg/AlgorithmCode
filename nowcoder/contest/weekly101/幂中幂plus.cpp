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
// const int mod = 1e9 + 7;


int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

i64 qpow(i64 b, i64 e, i64 m) {
    i64 res = 1;
    b %= m;
    while (e > 0) {
        if (e & 1) res = (__int128)res * b % m;
        b = (__int128)b * b % m;
        e >>= 1;
    }
    return res;
}

i64 base, c0, mod;

i64 nex(i64 now) {
    if (mod == 1) return 0;

    int phi_mod = phi(mod);
    i64 exp = now;
    // bool f = false;
    if (now >= phi_mod)
        exp = (now % phi_mod) + phi_mod;
    return qpow(base, exp, mod);
}

void solve()
{
    std::cin >> base >> c0 >> mod;

    std::vector<i64> a; // circle
    a.push_back(0);
    std::vector<int> pos(mod, 0);

    i64 nowc = c0;
    int st = 0, len = 0;

    for (int i = 1; ; ++i) {
        i64 nexc = nex(nowc);

        if (pos[nexc] != 0) {
            st = pos[nexc];
            len = i - st;
            a.push_back(nexc);
            break;
        }

        pos[nexc] = i;
        a.push_back(nexc);
        nowc = nexc;
    }

    std::vector<i64> pre(a.size());
    for (size_t i = 1; i < a.size(); ++i) {
        pre[i] = (pre[i - 1] + a[i]) % mod;
    }
    i64 lstsum = pre[st - 1];
    i64 Csum = (pre[st + len - 1] - lstsum + mod) % mod;

    int q; std::cin >> q;
    while (q--) {
        i64 k;  std::cin >> k;
        i64 ans = 0;
        if (k < st)  ans = pre[k];
        else {
            ans = lstsum;

            i64 p = k - (st - 1);
            i64 cnt = p / len;
            i64 leftlen = p % len;
            ans = (ans + (cnt % mod) * Csum) % mod;
            if (leftlen > 0) {
                i64 leftsum = (pre[st + leftlen - 1] - lstsum + mod) % mod;
                ans = (ans + leftsum) % mod;
            }
        }
        std::cout << ans << "\n";
    }
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