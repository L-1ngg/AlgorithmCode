#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first 
#define y second

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

struct node {
    char c[2];
    int a[2];
};

void solve()
{
    int n;  std::cin >> n;
    std::vector<node> arr(n + 1);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j <= 1; j++)
            std::cin >> arr[i].c[j] >> arr[i].a[j];
    }

    std::vector<pii> dp(n + 2, { 0,0 });
    dp[n + 1].x = 1, dp[n + 1].y = 1;

    for (int i = n;i >= 1;i--) {
        dp[i].x = dp[i + 1].x + (arr[i].c[0] == 'x' ? arr[i].a[0] - 1 : 0) * std::max(dp[i + 1].x, dp[i + 1].y);
        dp[i].y = dp[i + 1].y + (arr[i].c[1] == 'x' ? arr[i].a[1] - 1 : 0) * std::max(dp[i + 1].x, dp[i + 1].y);
    }

    i64 ans = 0;
    for (int i = 1; i <= n;i++)
    {
        i64 sum = 0;
        if (arr[i].c[0] == '+')
            sum += arr[i].a[0];
        if (arr[i].c[1] == '+')
            sum += arr[i].a[1];
        ans += sum * std::max(dp[i + 1].x, dp[i + 1].y);
    }
    std::cout << ans + dp[1].x + dp[1].y << '\n';
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