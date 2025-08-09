#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

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
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1);
    std::vector dp(n + 1, std::vector<i64>(k + 1, INF));

    dp[0][0] = 0;
    for (int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        dp[i][0] = dp[i - 1][0] + a[i];
    }

    for (int i = 1;i <= n;i++)
        for (int j = 0;j <= k;j++)
        {
            int mn = INF;
            for (int t = 0;t + j <= k && i + t <= n;t++)
            {
                mn = std::min(mn, a[i + t]);
                dp[i + t][t + j] = std::min(dp[i + t][t + j], dp[i - 1][j] + mn * (t + 1));
            }
        }
    std::cout << *std::min_element(dp[n].begin(), dp[n].end());
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}