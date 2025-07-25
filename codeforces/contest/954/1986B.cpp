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
    std::vector a(n + 2, std::vector<int>(m + 2));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            std::cin >> a[i][j];

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            int mx = 0;
            for (int k = 0;k < 4;k++)
                mx = std::max(mx, a[i + dx[k]][j + dy[k]]);
            a[i][j] = std::min(mx, a[i][j]);
        }

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            std::cout << a[i][j] << " \n"[j == m];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}