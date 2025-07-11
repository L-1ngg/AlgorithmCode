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
const i64 inf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<i64> a(n + 1, 0);

    for (int i = 1; i <= n;i++)
    {
        std::cin >> a[i];
    }
    i64 x;
    std::cin >> x;

    a[1] = std::min(a[1], x - a[1]);
    bool f = 0;
    for (int i = 2; i <= n; i++)
    {
        i64 mn = std::min(a[i], x - a[i]);
        if (mn >= a[i - 1])
            a[i] = mn;
        else
        {
            i64 mx = std::max(a[i], x - a[i]);
            if (mx >= a[i - 1])
                a[i] = mx;
            else
            {
                f = 1;break;
            }
        }
    }

    if (f)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";

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