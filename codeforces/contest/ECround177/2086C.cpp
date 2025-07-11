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
const int mod = 998244353;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1), d(n + 1), vis(n + 1, 0);
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];
    for (int i = 1; i <= n;i++)
        std::cin >> d[i];

    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        if (vis[d[i]]) {
            std::cout << ans << " ";
            continue;
        }
        if (a[d[i]] == d[i]) {
            vis[d[i]] = 1;
            ans++;
        }
        else {
            int p = d[i];
            while (!vis[p]) {
                vis[p] = 1;
                ans++;
                p = a[p];
            }
        }
        std::cout << ans << " ";
    }
    std::cout << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}