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
    int n;  std::cin >> n;
    if (n & 1)
    {
        for (int i = 1; i <= n;i++)
        {
            if (i == n / 2 + 1)
            {
                std::cout << "=";
                continue;
            }
            std::cout << "-";
        }
    }
    else
        for (int i = 1; i <= n;i++)
        {
            if (i == n / 2 || i == n / 2 + 1)
                std::cout << "=";
            else std::cout << "-";
        }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}