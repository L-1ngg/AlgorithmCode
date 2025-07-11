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
    std::vector<i64> a(n + 1), s(n + 1);
    for (int i = 1; i <= n;i++)
    {
        std::cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int k = 0;k <= n - 3;k++)
    {
        std::vector<i64> pre(n + 1), suf(n + 2);
        for (int i = 1; i <= n;i++)
        {
            pre[i] = std::max(pre[i - 1], s[i] - s[std::max(0, i - k - 1)]);
        }
        for (int i = 1; i <= n;i++)
        {
            suf[n - i + 1] = std::max(suf[n - i + 2], s[std::min(n, n - i + k + 1)] - s[n - i]);
        }
        i64 ans = 0;
        for (int i = 1; i <= n;i++)
            ans = std::max(ans, std::max(pre[i - 1], suf[i + 1]) - a[i]);
        std::cout << ans << ' ';
    }
    std::cout << std::max(s[n] - s[1] - a[1], s[n - 1] - a[n]) << " 0\n";
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