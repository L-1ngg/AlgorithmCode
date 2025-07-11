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
    int n, m;   std::cin >> n >> m;
    std::vector<i64> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= m; i++)
        std::cin >> b[i];

    ranges::sort(b.begin() + 1, b.end());
    a[1] = std::min(a[1], b[1] - a[1]);
    bool f = 1;

    for (int i = 2; i <= n; i++)
    {
        auto it = std::lower_bound(b.begin() + 1, b.end(), a[i] + a[i - 1]);
        if (it != b.end())
        {
            if (a[i] >= a[i - 1])
                a[i] = std::min(a[i], *it - a[i]);
            else
                a[i] = *it - a[i];
        }

        if (a[i] < a[i - 1])
        {
            f = 0;
            break;
        }
    }
    // std::cout << a[4];
    // std::cout << *std::upper_bound(b.begin() + 1, b.end(), 8);
    std::cout << (f ? "YES\n" : "NO\n");
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