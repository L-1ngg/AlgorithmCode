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
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++)
        std::cin >> a[i];
    for (int i = 1;i <= n;i++)
        std::cin >> b[i];

    std::vector<pii> ans;
    for (int i = 1;i <= n;i++) {
        if (a[i] > b[i])
        {
            std::swap(a[i], b[i]);
            ans.push_back({ 3,i });
        }
    }

    for (int i = 1;i <= n - 1;i++)
    {
        for (int j = 1;j <= n - i;j++) {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                ans.push_back({ 1,j });
            }
            if (b[j] > b[j + 1])
            {
                std::swap(b[j], b[j + 1]);
                ans.push_back({ 2,j });
            }
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        std::cout << x << " " << y << '\n';
    // for (int i = 1;i <= n;i++)
    //     std::cout << a[i] << " \n"[i == n];
    // for (int i = 1;i <= n;i++)
    //     std::cout << b[i] << " \n"[i == n];
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