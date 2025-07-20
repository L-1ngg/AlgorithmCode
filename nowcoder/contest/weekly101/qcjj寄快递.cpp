#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using ld = long double;

using pii = std::pair<int, int>;
using pll = std::pair<ld, ld>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;
const ld eps = 1e-7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<pll> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i].first >> a[i].second;
    ld ans = 0;

    auto cal = [&](int i) {
        ld dis = (a[i].first - a[i - 1].first) * (a[i].first - a[i - 1].first)
            + (a[i].second - a[i - 1].second) * (a[i].second - a[i - 1].second);
        return std::sqrt(dis);
        };

    for (int i = 2;i <= n;i++) {
        ld dis = cal(i);
        auto check = [&](ld x) {
            return  2.0 * x + (ld)2.0 * dis / std::pow(2.0, x);
            };

        ld l = 0, r = 8;
        while (r - l >= eps) {
            ld mid1 = (l * 2.0 + r) / 3.0;
            ld mid2 = (l + r * 2.0) / 3.0;
            if (check(mid1) < check(mid2))
                r = mid2;
            else l = mid1;
        }

        ans += check(l);
    }
    std::cout << std::fixed << std::setprecision(8) << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
        solve();
}