#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 405;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)
        std::cin >> x;

    i64 dp[N][N] = { 0 };
    for (int len = 3; len <= n;len++)
    {
        for (int i = 0; i + len - 1 < n;i++)
        {
            int j = i + len - 1;
            for (int k = i + 1;k < j;k++)
                dp[i][j] = std::max(dp[i][j], a[i] * a[j] * a[k] + dp[i + 1][k - 1] + dp[k + 1][j - 1]);
            for (int k = i;k < j;k++)
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    std::cout << dp[0][n - 1] << '\n';
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