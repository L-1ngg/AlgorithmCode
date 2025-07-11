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
    int n, x;i64 k;
    std::cin >> n >> x >> k;
    std::string s;  std::cin >> s;
    s = " " + s;

    i64 tmp = 0, i1 = -1, i2 = -1;
    for (int i = 1;i <= n; i++)
    {
        if (s[i] == 'L')
            tmp--;
        else tmp++;

        if (tmp + x == 0 && i1 == -1)
            i1 = i;
        if (tmp == 0 && i2 == -1)
            i2 = i;
    }
    if (i1 == -1)
    {
        std::cout << "0\n";
    }
    else
    {
        if (i2 == -1)
            std::cout << "1\n";
        else
            // std::cout << i1 << ' ' << i2;
            std::cout << (k - i1) / i2 + 1ll << '\n';
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