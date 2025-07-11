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
    int x[3], y[3];
    for (int i = 0; i < 3;i++)
        std::cin >> x[i] >> y[i];

    for (int i = 0;i < 3;i++)
    {
        if (x[i] * 2 == x[(i + 1) % 3] + x[(i + 2) % 3])
        {
            std::cout << "YES\n";
            return;
        }
        if (y[i] * 2 == y[(i + 1) % 3] + y[(i + 2) % 3])
        {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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