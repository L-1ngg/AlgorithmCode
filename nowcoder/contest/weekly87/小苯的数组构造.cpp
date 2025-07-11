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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;


void solve()
{
    int n, x, y;    std::cin >> n >> x >> y;

    if ((x | y) != x)
    {
        std::cout << "NO\n";
        return;
    }
    if (n == 1 && x != y)
    {
        std::cout << "NO\n";
        return;
    }
    if (!(n & 1))
    {
        if (x == y)
        {
            std::bitset<32> a(x);
            if (a.count() == 1)
            {
                std::cout << "NO\n";
                return;
            }
            std::cout << "YES\n";
            for (int i = 0; i < 32;i++)
            {
                if (a[i])
                {
                    std::cout << (1 << i) << " ";
                    a[i] = 0;
                    std::cout << a.to_ullong() << " ";
                    break;
                }
            }
            for (int i = 1; i <= n - 2;i++)
                std::cout << x << " \n"[i == n - 2];
            return;
        }

        std::cout << "YES\n";
        for (int i = 1; i <= n - 1;i++)
            std::cout << x << " ";
        std::cout << (x ^ y) << '\n';
    }
    else
    {
        std::cout << "YES\n";
        for (int i = 1; i <= n - 1;i++)
            std::cout << x << " ";
        std::cout << y << '\n';
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