#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<a2> a(n + 1);
    std::vector<int> b(n + 1);
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i][0] >> a[i][1];
        b[i] = a[i][1] - a[i][0];
    }
    std::vector<a2> dp(n + 1, { inf ,inf });
    dp[1][0] = b[1] + a[1][1] - 1;
    dp[1][1] = a[1][1] - 1;
    for (int i = 2;i <= n;i++) {
        dp[i][0] = std::min(dp[i - 1][0] + std::abs(a[i - 1][0] - a[i][1]), dp[i - 1][1] + std::abs(a[i - 1][1] - a[i][1])) + 1 + b[i];
        dp[i][1] = std::min(dp[i - 1][0] + std::abs(a[i - 1][0] - a[i][0]), dp[i - 1][1] + std::abs(a[i - 1][1] - a[i][0])) + 1 + b[i];
    }
    std::cout << std::min(dp[n][0] + std::abs(n - a[n][0]), dp[n][1] + std::abs(n - a[n][1]));
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}