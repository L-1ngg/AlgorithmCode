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
    std::vector<i64> a(n + 1);
    for (int i = 1;i <= n;i++)  std::cin >> a[i];
    i64 x, y;
    if ((2 * a[1] - a[2]) % (n + 1) != 0) {
        std::cout << "NO\n";
        return;
    }
    y = (2 * a[1] - a[2]) / (n + 1);
    x = a[1] - n * y;
    if (x < 0 || y < 0) {
        std::cout << "NO\n";
        return;
    }
    for (int i = 1;i <= n;i++)
        if (i * x + (n - i + 1) * y != a[i]) {
            std::cout << "NO\n";
            return;
        }
    std::cout << "YES\n";
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