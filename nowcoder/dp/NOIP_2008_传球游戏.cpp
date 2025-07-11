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
    int n, m;  std::cin >> n >> m;

    std::vector<std::vector<i64>> dp(m + 1, std::vector<i64>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < n;j++)
        {
            dp[i][j] = dp[i - 1][(j - 1 + n) % n] + dp[i - 1][(j + 1) % n];
        }

    std::cout << dp[m][0];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}