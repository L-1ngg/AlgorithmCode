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
const i64 inf = 1e18;
const int mod = 1e9 + 7;

i64 dp[10005][1005];
void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    //dp
    memset(dp, -0x3f3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = i; j <= 6 * i;j++)
        {
            // dp[j][i] = std::max(dp[j][i], dp[std::max(0, j - 1)][i - 1] + a[j]);
            // dp[j][i] = std::max(dp[j][i], dp[std::max(0, j - 2)][i - 1] + a[j]);
            // dp[j][i] = std::max(dp[j][i], dp[std::max(0, j - 3)][i - 1] + a[j]);
            // dp[j][i] = std::max(dp[j][i], dp[std::max(0, j - 4)][i - 1] + a[j]);
            // dp[j][i] = std::max(dp[j][i], dp[std::max(0, j - 5)][i - 1] + a[j]);
            // dp[j][i] = std::max(dp[j][i], dp[std::max(0, j - 6)][i - 1] + a[j]);
            dp[j][i] = std::max({ dp[j][i], std::max({dp[std::max(0, j - 1)][i - 1] ,dp[std::max(0, j - 2)][i - 1] ,dp[std::max(0, j - 3)][i - 1] ,dp[std::max(0, j - 4)][i - 1] ,dp[std::max(0, j - 5)][i - 1] ,dp[std::max(0, j - 6)][i - 1]}) + a[j] });
        }
    i64 ans = -inf;
    for (int i = k; i <= 6 * k;i++)
        ans = std::max(ans, dp[i][k]);
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}