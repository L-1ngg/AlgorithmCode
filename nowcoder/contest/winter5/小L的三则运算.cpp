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
    i64 x;
    char c;
    std::cin >> x >> c;
    if (c == '*')
        std::cout << x << " 1";
    if (c == '-')
        std::cout << x + 1ll << " 1";
    if (c == '+')
        std::cout << x - 1ll << " 1";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}