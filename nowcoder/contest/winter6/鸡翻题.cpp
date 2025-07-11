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
const int mod = 1e9 + 7;

void solve()
{
    int x, y;   std::cin >> x >> y;
    if ((y & 1) == 0)
        std::cout << "NO\n";
    else
    {
        int num = (y - 1) / 2;
        if ((num + x) % 2 == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
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