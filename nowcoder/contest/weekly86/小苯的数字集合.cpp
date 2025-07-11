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
    int x, y; std::cin >> x >> y;
    int a = x & y, b = x | y, c = x ^ y, d = std::gcd(x, y);
    if (a == 0 || c == 0) { std::cout << "1\n"; return; }
    for (auto i : { a,b,c,d })
        for (auto j : { x,y })
        {
            if (!(i ^ j) || !(i & j))
            {
                std::cout << "2\n";
                return;
            }
        }
    std::cout << "3\n";
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