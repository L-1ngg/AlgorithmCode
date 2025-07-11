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

void solve()
{
    int n; std::cin >> n;
    std::vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    std::vector<pii> b(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        b[i].first = a[i];
        if (i == 2 * n)
            b[i].second = a[1];
        else
            b[i].second = a[i + 1];
    }

    int dp[205][205] = { 0 };
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= 2 * n - len; i++)
        {
            int j = len + i - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j] + b[i].first * b[k + 1].first * b[j].second);
        }

    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx = std::max(mx, dp[i][i + n - 1]);
    std::cout << mx;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}