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
    i64 n, l, r;    std::cin >> n >> l >> r;
    auto check = [&](i64 x)
        {
            i64 ret = -1;
            i64 l = 1ll, r = n;
            i64 m;
            while (l <= r)
            {
                m = (r + l) >> 1ll;
                i64 num = (1ll + m) * m / 2;
                if (num >= x)
                {
                    ret = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            return ret;
        };
    if (check(l) == check(r))
        std::cout << "Yes\n";
    else if (check(r) - check(l) == 1)
    {
        int step = check(l);
        if (l + step > r)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    else
        std::cout << "No\n";
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