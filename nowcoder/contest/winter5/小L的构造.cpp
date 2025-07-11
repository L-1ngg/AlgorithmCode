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
    int n;

    if (n <= 3)
    {
        std::cout << "0\n";
        return;
    }
    else
    {
        std::cout << n / 3 << '\n';
        std::cout << "1 2 4\n";
        if (n >= 6)
        {
            std::cout << "3 5 6\n";
            int i = 7;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}