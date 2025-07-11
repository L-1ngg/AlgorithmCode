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
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<char>> a(n + 1, std::vector<char>(n + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            std::cin >> a[i][j];

    std::vector<std::vector<i64>> dp(n + 2, std::vector<i64>(n + 2, 0));
    dp[1][1] = (1ll << (n + 1));
    // std::cout << dp[1][1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i;j++)
        {
            if (a[i][j] == '*')
            {
                dp[i + 1][j] += (dp[i][j] >> 1);
                dp[i + 1][j + 1] += (dp[i][j] >> 1);
            }
            else
                dp[i + 2][j + 1] += dp[i][j];
        }

    // std::cout << dp[n + 1][m + 1];
    i64 yinzi = std::gcd(dp[n + 1][m + 1], dp[1][1]);
    std::cout << dp[n + 1][m + 1] / yinzi << "/" << dp[1][1] / yinzi;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}