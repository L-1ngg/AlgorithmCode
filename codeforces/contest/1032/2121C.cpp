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
    int n, m;   std::cin >> n >> m;
    std::vector a(n + 1, std::vector<int>(m + 1));
    int mx = 0, cnt = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] > mx)  mx = a[i][j], cnt = 1;
            else if (a[i][j] == mx) cnt++;
        }

    std::vector<int> r(n + 1), c(m + 1);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (a[i][j] == mx)
                r[i]++, c[j]++;

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (r[i] + c[j] - (a[i][j] == mx) == cnt)
            {
                std::cout << mx - 1;
                return;
            }
    std::cout << mx;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
}