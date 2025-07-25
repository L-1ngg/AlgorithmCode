#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
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
    int mx = std::min(n, 100);
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];

    int ans = 0;
    for (int i = 1;i <= mx;i++) {
        std::vector<int> b(n + 1);
        for (int j = 1;j <= n;j++) b[j] = (a[j] >= i ? 1 : -1);
        std::vector<int> pre(n + 1);
        for (int j = 1;j <= n;j++) pre[j] = pre[j - 1] + b[j];

        std::vector<int> premn(n + 1), sufmx(n + 1);
        premn[0] = 0, sufmx[n] = pre[n];
        for (int j = 1;j <= n;j++)
            premn[j] = std::min(premn[j - 1], pre[j]);
        for (int j = n - 1;j >= 1;j--)
            sufmx[j] = std::max(sufmx[j + 1], pre[j]);

        for (int j = 1;j <= n;j++)
            if (premn[j - 1] <= pre[j] || pre[j - 1] <= sufmx[j])
                ans = std::max(ans, i - a[j]);
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}