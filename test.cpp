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
//     int n, m;   std::cin >> n >> m;
//     std::vector<int> a(n + 1), b(m + 1);
//     for (int i = 1;i <= n;i++)   std::cin >> a[i];
//     for (int i = 1;i <= m;i++)   std::cin >> b[i];
//     std::sort(b.begin() + 1, b.end());

//     a[n] = std::max(a[n], b[m] - a[n]);
//     for (int i = n - 1;i >= 1;i--) {
//         int j = std::upper_bound(b.begin() + 1, b.end(), a[i] + a[i + 1]) - b.begin() - 1;
//         if (j < 1 && a[i] > a[i + 1]) {
//             std::cout << "NO\n";
//             return;
//         }
//         if (a[i] > a[i + 1] || b[j] - a[i] > a[i])
//             a[i] = b[j] - a[i];
//     }
//     std::cout << "YES\n";
// }
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + 1), b(m + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= m;i++)   std::cin >> b[i];
    std::sort(b.begin() + 1, b.end());
    a[0] = -inf;
    for (int i = 1;i <= n;i++) {
        int p = std::lower_bound(b.begin() + 1, b.end(), a[i - 1] + a[i]) - b.begin();
        if (p == m + 1 && a[i] < a[i - 1]) {
            std::cout << "NO\n";
            return;
        }
        if (p == m + 1) continue;
        if (a[i] >= a[i - 1]) a[i] = std::min(a[i], b[p] - a[i]);
        else a[i] = b[p] - a[i];
    }
    std::cout << "YES\n";
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