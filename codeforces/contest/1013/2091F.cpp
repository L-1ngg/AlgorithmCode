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

// i64 dp[2005][2005][3];
char c[2005][2005];
i64 pre[2005];

void solve()
{
    int n, m, d;    std::cin >> n >> m >> d;
    std::vector<std::vector<a3>> dp(n + 1, std::vector<a3>(m + 1, { 0,0,0 }));
    for (int i = 1;i <= n;i++)
        for (int j = 1; j <= m;j++)
            std::cin >> c[i][j];

    for (int j = 1;j <= m;j++)
        if (c[n][j] == 'X')
            dp[n][j][1] = 1;


    pre[0] = 0;
    for (int j = 1; j <= m;j++)
        pre[j] = pre[j - 1] + dp[n][j][1];

    for (int j = 1; j <= m;j++)
    {
        if (c[n][j] == '#')  continue;
        int L = std::max(1, j - d), R = std::min(m, j + d);
        dp[n][j][2] = (pre[R] - pre[L - 1] - dp[n][j][1]) % mod;
    }


    for (int i = n - 1;i >= 1;i--)
    {
        pre[0] = 0;
        for (int j = 1; j <= m;j++)
            pre[j] = pre[j - 1] + dp[i + 1][j][1] + dp[i + 1][j][2];

        for (int j = 1; j <= m;j++)
        {
            if (c[i][j] == '#')  continue;
            int L = std::max(1, j - d + 1), R = std::min(m, j + d - 1);
            dp[i][j][1] = (pre[R] - pre[L - 1]) % mod;
        }

        pre[0] = 0;
        for (int j = 1; j <= m;j++)
            pre[j] = pre[j - 1] + dp[i][j][1];

        for (int j = 1; j <= m;j++)
        {
            if (c[i][j] == '#')  continue;
            int L = std::max(1, j - d), R = std::min(m, j + d);

            dp[i][j][2] = (pre[R] - pre[L - 1] - dp[i][j][1]) % mod;
        }
    }
    i64 ans = 0;
    for (int j = 1; j <= m;j++)
    {
        if (c[1][j] == 'X')
            ans += dp[1][j][1] + dp[1][j][2];
    }
    std::cout << ans % mod << '\n';
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