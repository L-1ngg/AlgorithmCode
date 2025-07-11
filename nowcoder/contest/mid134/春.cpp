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

i64 qpow(i64 x, i64 p)
{
    i64 ret = 1;
    while (p)
    {
        if (p & 1) ret = ret * x;
        p >>= 1;
        x = x * x;
    }
    return ret;
}

void solve()
{
    i64 x, y;   std::cin >> x >> y;
    if (x == 1)
        std::cout << qpow(10, 1) + y;
    else if (x == 2)
        std::cout << qpow(10, 9) + y;
    else
        std::cout << qpow(10, 18) + y;

    std::cout << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}