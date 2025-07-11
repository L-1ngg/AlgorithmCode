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
    int l, r, k, x; std::cin >> l >> r >> k >> x;
    k -= 1;
    if (k % 4 == 2)
        k += 1;
    else if (k % 4 == 1)
        k = 1;
    else if (k % 4 == 3)
        k = 0;
    x ^= k;

    if (x == 0)
    {
        for (int i = l; i <= r;i++)
        {
            if (i % 4 == 3)
            {
                std::cout << i << '\n';
                return;
            }
        }
        std::cout << "-1\n";
    }
    else if (x == 1)
    {
        for (int i = l; i <= r;i++)
        {
            if (i % 4 == 1)
            {
                std::cout << i << '\n';
                return;
            }
        }
        std::cout << "-1\n";
    }
    else
    {
        if (x % 4 == 0 && l <= x && x <= r)
        {
            std::cout << x << '\n';
            return;
        }
        if (x % 4 == 3 && l <= x - 1 && x - 1 <= r)
        {
            std::cout << x - 1 << '\n';
            return;
        }
        std::cout << "-1\n";
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