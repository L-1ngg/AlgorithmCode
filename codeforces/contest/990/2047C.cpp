#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int inf = 1e9;

void solve()
{
    int n;  std::cin >> n;
    std::vector<pii> a(n);
    for (int tt = 0; tt < 2;tt++)
        for (int i = 0; i < n;i++) {
            if (!tt) std::cin >> a[i].x;
            else std::cin >> a[i].y;
        }

    int ans = 0;
    int mx = -inf;
    for (int i = 0; i < n; i++) {
        ans += std::max(a[i].x, a[i].y);
        mx = std::max(mx, std::min(a[i].x, a[i].y));
    }
    std::cout << ans + mx << '\n';
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