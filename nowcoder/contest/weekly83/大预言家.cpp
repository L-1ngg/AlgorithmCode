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
    i64 t;  std::cin >> t;
    i64 num = sqrt(t);
    if (num & 1)
    {
        int x = (num - 1) / 2;
        int y = x;
        int d = (t - num * num);
        if (d <= 1)
            x += d;
        else if (d <= 1 + num)
            x++, y -= (d - 1);
        else
        {
            x++, y -= num;
            x -= (d - 1 - num);
        }
        std::cout << x << ' ' << y << '\n';
    }
    else
    {
        int x = -(num - 2) / 2;
        int y = x - 1;
        int d = (t - num * num);
        if (d <= 1)
            x -= d;
        else if (d <= 1 + num)
            x--, y += (d - 1);
        else if (d <= 1 + num * 2)
        {
            x--, y += num;
            x += (d - 1 - num);
        }
        std::cout << x << ' ' << y << '\n';
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