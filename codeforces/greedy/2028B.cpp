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
    i64 n, b, c;    std::cin >> n >> b >> c;
    if (b == 0 && n - c > 2)
        std::cout << "-1\n";
    else if (b == 0 && n - c <= 2)
        std::cout << (c >= n ? n : n - 1) << '\n';
    else
    {
        auto check = [&]()
            {
                i64 ret = -1;
                i64 l = 0, r = n - 1;
                i64 m = 0;
                while (l <= r)
                {
                    m = (l + r) / 2ll;
                    if (m <= (n - 1ll - c) / b)
                        l = m + 1;
                    else
                        r = m - 1;
                }
                return l;
            };

        i64 i = check();
        if (c >= n)
            i = 0;
        std::cout << n - i << '\n';
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