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
    int n, k;   std::cin >> n >> k;
    for (int i = 1; i <= n;i++)
        k -= i * i;

    if (k < 0)
    {
        std::cout << "-1";
        return;
    }

    std::vector<int> a(n + 2, 0);
    for (int i = n; i >= 1; i--)
        a[i] = a[i + 1] + i;

    std::vector<int> dp(k + 1);
    std::vector<pii> path(k + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= k; j++)
        {
            if (dp[j - a[i]] && !dp[j])
            {
                dp[j] = 1;
                path[j] = { j - a[i],i };
            }
        }

    if (!dp[k])
    {
        std::cout << "-1";
        return;
    }

    std::vector<int> ans(n + 1, 0);
    int cur = k;

    while (cur != 0)
    {
        auto [pre, x] = path[cur];
        ans[x]++;
        cur = pre;
    }

    for (int i = 1; i <= n;i++)
        ans[i] += ans[i - 1];

    for (int i = 1; i <= n; i++)
    {
        ans[i] += i;
        std::cout << ans[i] << ' ';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}