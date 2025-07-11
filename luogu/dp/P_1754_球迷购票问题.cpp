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
const int mod = 1e9 + 7;

i64 dp[25][25];
void solve()
{
    int n;  std::cin >> n;
    for (int i = 1; i <= n;i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++) {
            if (i > j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (i == j) dp[i][j] = dp[i][j - 1];
        }
    std::cout << dp[n][n];
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}