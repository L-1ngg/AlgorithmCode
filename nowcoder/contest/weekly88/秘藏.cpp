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
    int n, k;   std::cin >> n >> k;
    std::vector<i64> a(n + 1), b(n + 1);
    std::vector<i64> dp1(n + 1, 0), dp2(n + 1, 0);
    for (int i = 1;i <= n;i++)
        std::cin >> a[i];
    for (int i = 1; i <= n;i++)
        std::cin >> b[i];

    dp1[1] = a[1];
    for (int i = 2;i <= n;i++)
    {
        dp1[i] = std::max(dp1[i], dp1[i - 1] + a[i]);
        if (dp2[i - 1])
            dp2[i] = std::max(dp2[i], dp2[i - 1] + b[i]);
        if (dp1[i - 1] >= k)
            dp2[i] = std::max(dp2[i], dp1[i - 1] - k + b[i]);
        if (dp2[i - 1] >= k)
            dp1[i] = std::max(dp1[i], dp2[i - 1] - k + a[i]);
    }
    std::cout << std::max(dp1[n], dp2[n]);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}