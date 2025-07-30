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

// void solve()
// {
//     int n;  std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1;i <= n;i++)   std::cin >> a[i];

//     std::vector<i64> dp(n + 1);
//     i64 sum = 0;
//     std::stack<pii> s;

//     for (int i = 1; i <= n; ++i) {
//         while (!s.empty() && s.top().first < a[i]) {
//             s.pop();
//         }
//         int k = 0;
//         if (!s.empty()) {
//             k = s.top().second;
//         }
//         dp[i] = dp[k] + (i64)i;
//         s.push({ a[i], i });
//         sum += dp[i];
//     }
//     std::cout << sum << '\n';
// }

// void solve() {
//     i64 n;  std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1;i <= n;i++)  std::cin >> a[i];
//     i64 ans = n * (n + 1) / 2;

//     for (int i = 2;i <= n;i++)
//         if (a[i - 1] > a[i])
//             ans += (i64)(i - 1) * (n - i + 1);
//     std::cout << ans << '\n';
// }

void solve() {
    i64 n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)  std::cin >> a[i];

    std::vector<i64> f(n + 1);
    a[0] = inf;
    f[1] = 1;
    for (int i = 2;i <= n;i++)
    {
        if (a[i] < a[i - 1]) f[i] = std::max(f[i], f[i - 1] + i);
        if (a[i] < a[i - 2]) f[i] = std::max(f[i], f[i - 2] + i);
    }
    std::cout << std::accumulate(f.begin(), f.end(), 0ll) << '\n';
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