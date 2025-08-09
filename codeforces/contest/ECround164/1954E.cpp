#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
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
    int n;  std::cin >> n;
    std::vector<int> a(n + 2, 0);
    int mx = 0;
    for (int i = 1;i <= n;i++)   std::cin >> a[i], mx = std::max(mx, a[i]);

    std::vector<int> ans(mx + 2, 0);
    for (int i = 1;i <= n;i++) {
        int cnt = 0;
        if (a[i] > a[i - 1]) cnt++;
        if (a[i] < a[i + 1]) cnt--;
        int r = mx;
        while (r) {
            int val = (a[i] + r - 1) / r;
            int l = (a[i] + val - 1) / val;
            ans[l] += cnt * val;
            ans[r + 1] -= cnt * val;
            r = l - 1;
        }
    }

    for (int i = 1;i <= mx;i++) ans[i] += ans[i - 1];
    for (int i = 1;i <= mx;i++)   std::cout << ans[i] << " ";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}