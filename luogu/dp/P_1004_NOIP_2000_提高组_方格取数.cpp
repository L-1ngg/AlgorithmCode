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

int dp[10][10][10][10];
int a[10][10];
void solve()
{
    int n;  std::cin >> n;
    int x, y, v;    std::cin >> x >> y >> v;
    while (1) {
        if (x == 0 && y == 0) break;
        a[x][y] = v;
        std::cin >> x >> y >> v;
    }

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            for (int k = 1;k <= n;k++)
                for (int l = 1; l <= n;l++) {
                    dp[i][j][k][l] = std::max({ dp[i][j - 1][k][l - 1] , dp[i][j - 1][k - 1][l] , dp[i - 1][j][k - 1][l] , dp[i - 1][j][k][l - 1] }) + a[i][j] + a[k][l] - ((i == k && j == l) ? a[k][l] : 0);
                }
    std::cout << dp[n][n][n][n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}