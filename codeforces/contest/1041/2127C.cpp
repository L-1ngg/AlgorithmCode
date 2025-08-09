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

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<pii> a(n + 1);
    i64 ans = 0;
    for (int i = 1;i <= n;i++)   std::cin >> a[i].x;
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i].y;
        if (a[i].x > a[i].y) std::swap(a[i].x, a[i].y);
        ans += std::abs(a[i].x - a[i].y);
    }

    std::sort(a.begin() + 1, a.end());
    int f = 0;
    for (int i = 2;i <= n;i++)
        if (a[i].x <= a[i - 1].y)
            f = 1;

    if (f)   std::cout << ans;
    else {
        // std::cout << 123;
        i64 mn = INF;
        for (int i = 2;i <= n;i++)
            mn = std::min(mn, (i64)a[i].y - a[i - 1].x + a[i].x - a[i - 1].y - (a[i - 1].y - a[i - 1].x + a[i].y - a[i].x));
        std::cout << ans + mn;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}