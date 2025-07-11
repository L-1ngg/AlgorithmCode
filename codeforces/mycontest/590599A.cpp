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
    i64 n, k;  std::cin >> n >> k;
    std::string s;  std::cin >> s;
    i64 x = 0, y = 0, mx = 0;
    for (int i = 1; i <= n;i++)
    {
        if (s[i - 1] == 'U')
            y++;
        else if (s[i - 1] == 'D')
            y--;
        else if (s[i - 1] == 'R')
            x++;
        else if (s[i - 1] == 'L')
            x--;
        mx = std::max(mx, std::abs(x) + std::abs(y));
    }
    x *= (k - 1), y *= (k - 1);

    for (int i = 1; i <= n;i++)
    {
        if (s[i - 1] == 'U')
            y++;
        else if (s[i - 1] == 'D')
            y--;
        else if (s[i - 1] == 'R')
            x++;
        else if (s[i - 1] == 'L')
            x--;
        mx = std::max(mx, std::abs(x) + std::abs(y));
    }

    std::cout << mx << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;std::cin >> t;
    while (t--)
        solve();
}