#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
// #define int long long

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
    int x1, x2, y1, y2;
    std::cin >> x1 >> x2 >> y1 >> y2;
    auto calc = [&](auto&& self, int x1, int x2, int y1, int y2) ->i64
        {
            if (x2 == x1)    return 0;
            if (x2 - x1 > y2 - y1)  return self(self, y1, y2, x1, x2);
            i64 res = 0;
            for (int x = x1;x < x2;)
            {
                int cnt0 = std::min(20, std::countr_zero(unsigned(x)));
                while (x + (1 << cnt0) > x2)    cnt0--;
                int wid = 1 << cnt0;
                int h1 = y1 >> cnt0 << cnt0, h2 = y2 >> cnt0 << cnt0;
                while (h1 < y1) h1 += wid;
                res += (h2 - h1) / wid;
                res += self(self, x, x + wid, y1, h1) + self(self, x, x + wid, h2, y2);
                x += wid;
            }
            return res;
        };
    std::cout << calc(calc, x1, x2, y1, y2) << '\n';

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