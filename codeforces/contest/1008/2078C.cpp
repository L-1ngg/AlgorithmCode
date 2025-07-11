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
    std::vector<int> b(2 * n + 1);
    for (int i = 1; i <= 2 * n;i++)
        std::cin >> b[i];

    ranges::sort(b);
    i64 mx = 0, mn = 0;
    for (int i = 1; i <= 2 * n;i++)
    {
        if (i <= n - 1)  mn += b[i];
        else if (i <= 2 * n - 1)   mx += b[i];
    }
    std::cout << b[2 * n] << ' ';
    std::cout << b[2 * n] + mx - mn << ' ' << b[n] << ' ';
    for (int i = 1; i <= n - 1;i++)
        std::cout << b[i] << " " << b[i + n] << ' ';
    std::cout << '\n';
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