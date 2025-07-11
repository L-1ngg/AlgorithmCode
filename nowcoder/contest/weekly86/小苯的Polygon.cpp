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

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    if (n <= 2)
    {
        std::cout << "-1\n";
        return;
    }
    std::sort(a.begin() + 1, a.end());

    int ans = inf;
    int sum = a[1] + a[2];
    std::vector<int> dp(202, 0);
    dp[0] = dp[a[1]] = dp[a[2]] = dp[a[1] + a[2]] = 1;
    //1 6 7 8 8
    for (int i = 3;i <= n;i++)
    {
        if (sum > a[i])
            for (int k = a[i] + 1;k <= 200;k++)
            {
                if (dp[k])
                    ans = std::min(ans, a[i] + k);
            }
        for (int j = 200; j >= a[i];j--)
            if (dp[j - a[i]])
                dp[j] = 1;

        sum += a[i];
    }
    std::cout << (ans == inf ? -1 : ans) << '\n';
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