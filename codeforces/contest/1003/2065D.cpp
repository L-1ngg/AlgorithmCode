#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++)
            std::cin >> a[i][j];

    std::vector<pii> sum(n);
    for (int i = 0; i < n; i++)
    {
        sum[i].second = i + 1;
        sum[i].first = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            sum[i - 1].first += a[i][j];
    }

    ranges::sort(sum.rbegin(), sum.rend());
    // for (int i = 1; i <= n; i++)
    //     std::cout << sum[i - 1].first;

    i64 ans = 0, pre = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m;j++)
        {
            pre += a[sum[i].second][j];
            ans += pre;
        }
    }
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