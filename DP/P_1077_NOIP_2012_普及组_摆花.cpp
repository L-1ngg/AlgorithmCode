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
const int mod = 1e6 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    std::vector f(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 0;i <= a[1];i++)   f[1][i] = 1;
    for (int i = 1;i <= n;i++) f[i][0] = 1;

    for (int i = 2;i <= n;i++)
        for (int j = 1;j <= m;j++)
            for (int k = 0;k <= a[i];k++)
            {
                if (j - k < 0) break;
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
    std::cout << f[n][m];
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