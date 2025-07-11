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
const int mod = 998244353;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> d(n + 1, 0);
    std::vector<int> p(n + 1, 0);
    d[1] = 1;

    int mx = 0;
    for (int i = 2; i <= n; i++)
    {
        std::cin >> p[i];
        d[i] = d[p[i]] + 1;
        mx = std::max(mx, d[i]);
    }

    std::vector<std::vector<int>> vec(mx + 1);
    for (int i = 1; i <= n; i++)
        vec[d[i]].push_back(i);

    std::vector<int> dp(n + 1);
    std::vector<int> pre(mx + 1);
    dp[1] = 1, pre[1] = 1;
    for (int i = 2; i <= mx; i++)
    {
        for (auto u : vec[i])
        {
            if (i == 2)
                dp[u] = pre[i - 1];
            else
                dp[u] = (pre[i - 1] + mod - dp[p[u]]) % mod;

            pre[i] += dp[u];
            pre[i] %= mod;
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n;i++)
        ans = (ans + dp[i]) % mod;
    std::cout << ans << '\n';
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