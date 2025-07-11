#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 60;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<std::vector<i64>> dp(N + 1, std::vector<i64>(N + 1, INF));

void solve()
{
    i64 X, Y;   std::cin >> X >> Y;

    i64 ans = INF;
    for (int i = 0;i <= N;i++)
        for (int j = 0; j <= N;j++)
            if ((X >> i) == (Y >> j))   ans = std::min(ans, dp[i][j]);
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    dp[0][0] = 0;
    for (int x = 1; x <= 30;x++)
    {
        for (int i = N;i >= 0;i--)
            for (int j = N;j >= 0;j--)
            {
                if (i - x >= 0)
                    dp[i][j] = std::min(dp[i][j], dp[i - x][j] + (1ll << x));
                if (j - x >= 0)
                    dp[i][j] = std::min(dp[i][j], dp[i][j - x] + (1ll << x));
            }
    }

    int t;
    std::cin >> t;
    while (t--)
        solve();
}