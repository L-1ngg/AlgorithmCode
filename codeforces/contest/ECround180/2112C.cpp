//  a1 + a2 > a3 && a1 + a2 + a3 > an
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
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());
    i64 ans = 0;
    for (int i = 1;i <= n - 2;i++)
        for (int j = i + 1;j <= n - 1;j++) {
            int p1 = std::upper_bound(a.begin(), a.end(), a[n] - a[i] - a[j]) - a.begin();
            int p2 = std::lower_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin();
            p2--;
            p1 = std::max(p1, j + 1);
            if (p2 < j + 1 || p1 > p2) continue;
            ans += p2 - p1 + 1;
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