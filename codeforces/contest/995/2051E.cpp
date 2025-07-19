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
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1), b(n + 1), v;
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        v.push_back(a[i]);
    }
    for (int i = 1;i <= n;i++) {
        std::cin >> b[i];
        v.push_back(b[i]);
    }

    std::sort(a.begin() + 1, a.end());
    std::sort(b.begin() + 1, b.end());
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    i64 ans = 0;
    for (auto x : v) {
        int cnt1 = n - (std::lower_bound(a.begin(), a.end(), x) - a.begin() - 1); //买 且好评的
        int cnt2 = n - (std::lower_bound(b.begin(), b.end(), x) - b.begin() - 1); //一定会买的
        if (cnt2 - cnt1 <= k)   ans = std::max(ans, (i64)x * cnt2);
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}