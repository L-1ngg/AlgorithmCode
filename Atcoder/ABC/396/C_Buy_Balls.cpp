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
    int cnt1 = 0, cnt2 = 0;
    std::vector<int>   a(n), b(m);
    i64 sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i - 1];
        if (a[i - 1] > 0)
        {
            sum1 += a[i - 1];
            cnt1++;
        }
    }
    for (int i = 1; i <= m;i++)
    {
        std::cin >> b[i - 1];
        if (b[i - 1] > 0)
        {
            cnt2++;
            sum2 += b[i - 1];
        }
    }
    if (cnt2 <= cnt1)
        std::cout << sum1 + sum2;
    else
    {
        std::sort(a.rbegin(), a.rend());
        std::sort(b.rbegin(), b.rend());
        i64 ans = 0;
        for (int i = 0; i < std::min(n, m);i++)
        {
            if (a[i] + b[i] >= 0)
                ans += (a[i] + b[i]);
            else
                break;
        }
        std::cout << ans;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}