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
    std::vector<std::string> a(n + 1);
    std::vector b(m + 1, std::vector<std::string>(n + 1));
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++)   std::cin >> b[i][j];

    for (int i = 1;i <= n;i++)
    {
        int f = 0;
        for (int j = 1;j <= m;j++) {
            if (a[i] == b[j][i]) {
                f = 1;
                break;
            }
        }
        if (!f) {
            std::cout << "-1\n";
            return;
        }
    }

    int min = inf;
    for (int i = 1;i <= m;i++)
    {
        int cnt = 0;
        for (int j = 1;j <= n;j++)
            if (a[j] != b[i][j])    cnt++;
        min = std::min(min, cnt);
    }
    std::cout << n + min * 2 << '\n';
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