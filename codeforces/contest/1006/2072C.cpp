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
    int n, x;   std::cin >> n >> x;
    int pos = 0;
    while (x)
    {
        if (x >> pos & 1)   pos++;
        else break;
    }

    std::vector<int> ans(n + 1);
    int res = 0;
    for (int i = 1; i <= n;i++)
    {
        if (i - 1 < (1ll << pos))
            ans[i] = i - 1;
        else ans[i] = 0;
        res |= ans[i];
    }
    if (res != x)   ans[n] = x;
    for (int i = 1; i <= n;i++)
        std::cout << ans[i] << ' ';
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