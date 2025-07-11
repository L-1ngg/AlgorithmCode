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
const i64 inf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector a(3, std::vector<i64>(n + 1));
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n;j++)
            std::cin >> a[i][j];

    std::vector sum(3, std::vector<i64>(n + 2, 0));
    std::vector<i64> mx1(n + 1, -inf), mx2(n + 2, -inf), dmx1(n + 1, -inf), dmx2(n + 2, -inf);

    for (int i = 1; i <= n; i++)
    {
        sum[1][i] = sum[1][i - 1] + a[1][i];
        mx1[i] = std::max(mx1[i - 1], a[2][i]);
        dmx1[i] = std::max(dmx1[i - 1], a[2][i] - a[1][i]);
    }
    for (int i = n;i >= 1; i--)
    {
        sum[2][i] = sum[2][i + 1] + a[2][i];
        mx2[i] = std::max(mx2[i + 1], a[1][i]);
        dmx2[i] = std::max(dmx2[i + 1], a[1][i] - a[2][i]);
    }

    i64 ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        ans = std::max(ans, sum[1][i] + sum[2][i]);
        ans = std::max(ans, sum[1][i] + sum[2][i] + dmx1[i - 1] + dmx2[i + 1]);
        ans = std::max(ans, sum[1][i] + sum[2][i] - a[2][i] + mx1[i - 1]);
        ans = std::max(ans, sum[1][i] + sum[2][i] - a[1][i] + mx2[i + 1]);
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