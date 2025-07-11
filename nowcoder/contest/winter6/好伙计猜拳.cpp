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
    i64 n, c1, c2; std::cin >> n >> c1 >> c2;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n; i++)
        std::cin >> a[i] >> b[i];

    std::vector<std::array<i64, 2>> dp(n + 1, { (i64)1e18, (i64)1e18 });

    dp[1][0] = 0, dp[1][1] = c2;
    dp[0][0] = 0, dp[0][1] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j] && b[i] >= b[j])
            {
                dp[i][0] = std::min(dp[i][0], dp[j][0] + (i - j - 1) * c1);
                dp[i][1] = std::min(dp[i][1], dp[j][1] + (i - j - 1) * c1 + c2);
            }
            if (a[i] >= b[j] && b[i] >= a[j])
            {
                dp[i][0] = std::min(dp[i][0], dp[j][1] + (i - j - 1) * c1);
                dp[i][1] = std::min(dp[i][1], dp[j][0] + (i - j - 1) * c1 + c2);
            }
        }
    }

    i64 ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = std::min(ans, dp[i][0] + (n - i) * c1);
        ans = std::min(ans, dp[i][1] + (n - i) * c1);
    }
    std::cout << ans << '\n';
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