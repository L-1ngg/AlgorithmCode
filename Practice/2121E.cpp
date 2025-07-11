#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    std::string l, r;   std::cin >> l >> r;
    int i = 0;
    int ans = 0;
    while (i < l.size() && l[i] == r[i])
        i++;
    ans = 2 * i;
    if (i == l.size() || r[i] - l[i] > 1)
        std::cout << ans << '\n';
    else {
        i++;
        int cntl = 0, cntr = 0;
        while (i + cntl < l.size() && l[i + cntl] == '9') cntl++;
        while (i + cntr < r.size() && r[i + cntr] == '0') cntr++;
        std::cout << ans + std::min(cntl, cntr) + 1 << '\n';
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