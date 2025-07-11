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
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(m + 1);
    for (int i = 1;i <= m;i++)  std::cin >> a[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, inf));
    for (int i = 1;i <= n;i++)
        for (int j = 1; j <= n;j++)
            std::cin >> f[i][j];
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1; j <= n;j++)
                f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
    int ans = 0;
    for (int i = 2; i <= m;i++) ans += f[a[i - 1]][a[i]];
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}