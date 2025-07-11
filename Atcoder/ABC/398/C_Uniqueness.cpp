#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second

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
    std::map<int, pii> m;
    for (int i = 1; i <= n;i++)
    {
        int tmp;  std::cin >> tmp;
        m[tmp].x++;
        m[tmp].y = i;
    }

    int mx = 0;
    int ans = 0;
    for (auto [num, p] : m)
    {
        if (p.x == 1)
        {
            if (mx < num)
            {
                mx = num;
                ans = p.y;
            }
        }
    }

    std::cout << (ans == 0 ? -1 : ans);
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