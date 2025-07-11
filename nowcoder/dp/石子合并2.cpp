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

void solve()
{
    int n;  std::cin >> n;
    std::vector<i64> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(n + 1, inf));

    for (int i = 1; i <= n;i++)
        dp[i][i] = 0;

    for (int len = 2; len <= n;len++)
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = len + i - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1]);
        }
    std::cout << dp[1][n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}