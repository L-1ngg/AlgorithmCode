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

i64 qpow(i64 x, i64 p)
{
    i64 ret = 1;
    while (p) {
        if (p & 1) ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void solve()
{
    i64 n, m, k;   std::cin >> n >> m >> k;
    int a = 0, b = 0;
    for (int i = 1;i <= k;i++)
    {
        int x, y, c;    std::cin >> x >> y >> c;
        if ((x == 1 && y == m) || (x == 1 && y == 1) || (x == n && y == m) || (x == n && y == 1))
            continue;
        if ((x == 1) || (x == n) || (y == 1) || (y == m))
            a++, b += c;
    }
    if (a == (n + m - 4) * 2)
        std::cout << ((b % 2) ? 0 : qpow(2, n * m - k)) << '\n';
    else std::cout << qpow(2, n * m - k - 1) << '\n';
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