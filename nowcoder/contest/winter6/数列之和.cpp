#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
// using i64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

void solve()
{
    i64 k;  std::cin >> k;

    auto check = [](i64 s, i64 e, i64 k)
        {
            i64 ret = -1;
            i64 m;
            while (s <= e)
            {
                m = s + (e - s) / 2;
                if (m - (std::__lg(m * 2ll) - 1) >= k)
                {
                    ret = m;
                    e = m - 1;
                }
                else if (m - (std::__lg(m * 2ll) - 1) < k)
                    s = m + 1;
            }
            return ret;
        };

    std::cout << 2ll * check(k, 2 * k, k) << '\n';
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