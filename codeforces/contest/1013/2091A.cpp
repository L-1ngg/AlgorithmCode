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
    int  a[10] = { 0 };
    int n;  std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        int x;  std::cin >> x;
        a[x]++;
        if (!ans && a[0] >= 3 && a[2] >= 2 && a[1] && a[3] && a[5])
            ans = i;
    }
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