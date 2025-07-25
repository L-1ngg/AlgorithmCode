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
    int n, m, k;    std::cin >> n >> m >> k;

    i64 l = 1, r = m;
    while (l <= r)
    {
        i64 mid = (l + r) >> 1;
        if (((m / (mid + 1)) * mid + (m % (mid + 1))) * n >= k)
            r = mid - 1;
        else l = mid + 1;
    }
    std::cout << l << '\n';
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