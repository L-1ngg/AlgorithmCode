#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 2000 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;


void solve()
{
    std::string a, b;   std::cin >> a >> b;
    int n1 = a.length(), n2 = b.length();
    a = " " + a, b = " " + b;
    std::vector<std::vector<int>> dp(N, std::vector<int>(N, inf));
    for (int i = 0; i <= n1;i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n2;i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n1;i++)
        for (int j = 1; j <= n2;j++)
        {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
            dp[i][j] = std::min({ dp[i][j],dp[i - 1][j] + 1,dp[i][j - 1] + 1 });
        }

    std::cout << dp[n1][n2];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}