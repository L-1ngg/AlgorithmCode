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
    int n, x, y;std::cin >> n >> x >> y;

    auto dc = [&](int atk, int r)
        {
            int atk2 = atk - r + 1;
            return (i64)(atk + atk2) * r / 2;
        };

    i64 ans = 0;
    for (int i = 1; i <= std::min(n, y);i++)
    {
        i64 tmp = 0;
        i64 atk = x + i;
        i64 r1 = std::min(n, y) - i + 1;
        tmp = atk * r1 + dc(atk - 1, std::min((i64)n - std::min(n, y), atk));
        ans = std::max(ans, tmp);
    }
    std::cout << ans << '\n';
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