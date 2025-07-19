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

void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<pii> a(q + 1);
    for (int i = 1;i <= q;i++) {
        std::cin >> a[i].first;
        std::string s;  std::cin >> s;
        a[i].second = (s == "+" ? 1 : 0);
    }

    std::vector f(1 << n + 1, std::vector<int>(n + 1, inf));
    std::vector d(n + 1, std::vector<int>(n + 1));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            if (i == j) continue;
            int dis = 1;
            int l = 1, r = 2;
            for (auto [x, op] : a) {
                if (x == i && op == 1) {
                    l++;
                    if (l == r)
                    {
                        dis++;
                        r++;
                    }
                }
                if (x == j && op == 0)
                    r++;
            }
            d[i][j] = dis;
        }

    for (int i = 1;i <= n;i++)
        f[1 << i][i] = 1;

    for (int i = (1 << 1);i < (1 << n + 1);i += 2)
        for (int j = 1;j <= n;j++)
        {
            for (int k = 1;k <= n;k++)
            {
                // if (i == 12 && j == 3) std::cout << "DEBUG";
                if (i >> k & 1) continue;
                f[i | (1 << k)][k] = std::min(f[i | (1 << k)][k], f[i][j] + d[j][k]);
            }
        }

    int ans = inf;
    for (int i = 1;i <= n;i++) {
        int res = f[(1 << n + 1) - 2][i];
        for (auto [x, op] : a)
            if (x == i && op == 1) res++;
        ans = std::min(ans, res);
    }
    std::cout << ans << '\n';

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
        solve();
}