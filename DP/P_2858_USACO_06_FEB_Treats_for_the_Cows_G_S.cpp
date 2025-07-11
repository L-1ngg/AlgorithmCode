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
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    std::vector f(n + 1, std::vector<i64>(n + 1));
    f[0][0] = 0;
    for (int i = 0;i <= n;i++)
        for (int j = 0; j + i <= n;j++) {
            if (i + 1 <= n) f[i + 1][j] = std::max(f[i + 1][j], (i + j + 1) * a[i + 1] + f[i][j]);
            if (j + 1 <= n) f[i][j + 1] = std::max(f[i][j + 1], (i + j + 1) * a[n - j] + f[i][j]);
        }
    i64 ans = 0;
    for (int i = 0;i <= n;i++)
        ans = std::max(ans, f[i][n - i]);
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}