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
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(2 * n + 1));

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= 2 * n;j++)
            std::cin >> a[i][j], a[i][j]++;

    std::vector<int> ans(n + 1);
    for (int i = 1;i <= n;i++) ans[i] = -1;
    //find 0
    int pos0;
    for (int i = 1;i <= n;i++)
    {
        int f = 0;
        for (int j = 1;j <= 2 * n;j += 2)
            if (!(a[i][j] == a[i][j + 1] && a[i][j] == i)) {
                f = 1;
                break;
            }
        if (!f)
        {
            pos0 = i;
            break;
        }
    }
    ans[pos0] = 0;
    //find 1
    int pos1;
    for (int i = 1;i <= n;i++) {
        int f = 0;
        for (int j = 1;j <= 2 * n;j += 2)
            if (!(a[i][j] == pos0 && a[i][j + 1] == (j + 1) / 2))
            {
                f = 1;
                break;
            }
        if (!f)
        {
            pos1 = i;
            break;
        }
    }
    ans[pos1] = 1;

    int cnt = 2;
    while (cnt < n) {
        for (int k = 1; k <= n; ++k) {
            if (ans[k] != -1) continue;
            int h = a[k][2 * k - 1];
            int l = a[k][2 * k];
            if (ans[h] != -1 && ans[l] != -1)
            {
                int num = ans[h] * n + ans[l];
                ans[k] = std::sqrt(num);
                cnt++;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}