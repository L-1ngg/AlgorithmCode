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
    std::bitset<31> bit(n);
    int p = -1;
    for (int i = 0; i < 30;i++)
    {
        if (bit[i] == 0 && bit[i + 1] == 1)
        {
            p = i;
            break;
        }
    }

    if (p == -1 || n - (n & -n) == 0)
        std::cout << "-1\n";
    else
    {
        bit[p] = 1, bit[p + 1] = 0;
        int ans = 0;
        for (int i = 0; i <= 30;i++)
            if (bit[i])
                ans |= (1 << i);
        std::cout << ans << '\n';
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