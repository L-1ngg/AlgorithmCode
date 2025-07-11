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
const int mod = 998244353;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1, 0), p(n + 1, 0);
    for (int i = 1;i <= n;i++)
        std::cin >> a[i];

    bool f = (a[n] == 1);
    for (int i = 2; i <= n;i++)
        if (a[i] > a[i - 1])
            f = 0;

    if (!f)
    {
        std::cout << "0\n";
        return;
    }

    for (int i = 1; i <= n;i++)
        if (a[i] != a[i - 1])
            p[i] = 1;

    int num = n - a[1];
    i64 ans = 1;
    for (int i = 2, j = 1; i <= n; i++)
    {
        if (!p[i])
            continue;
        if (num < i - j - 1)
        {
            f = 0;
            break;
        }
        int cnt = i - j - 1;
        while (cnt--)
            ans = ans * (num--) % mod;
        j = i;
        num += (a[i - 1] - a[i] - 1);
    }

    if (!f)
    {
        std::cout << "0\n";
        return;
    }
    while (num)
        ans = (ans * (num--)) % mod;
    std::cout << ans << '\n';

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