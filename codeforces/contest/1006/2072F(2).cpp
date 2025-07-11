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

/*'
    1
   1 1
  1 2 1
 1 3 3 1



*/
void solve()
{
    int n, k;   std::cin >> n >> k;
    n--;

    auto dfs = [&](auto&& self, unsigned int x) ->void
        {
            if (x == 0) std::cout << k << ' ';
            else if (x == 1) std::cout << k << ' ' << k << ' ';
            else {
                int w = std::bit_width(x);
                if (x == (1 << (w - 1)))
                {
                    std::cout << k << ' ';
                    for (int i = 0;i < x - 1;i++)
                        std::cout << "0 ";
                    std::cout << k << ' ';
                }
                else {
                    int d = x - (1 << (w - 1));
                    self(self, d);
                    for (int i = 0; i < x + 1 - (d + 1) * 2;i++)
                        std::cout << "0 ";
                    self(self, d);
                }
            }
        };

    dfs(dfs, n);
    std::cout << '\n';
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