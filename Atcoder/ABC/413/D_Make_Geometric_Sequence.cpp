#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
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
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    a2 cnt = { 0,0 };
    for (int i = 1;i <= n;i++) {
        if (a[i] == a[1]) cnt[0]++;
        if (a[i] == -a[1]) cnt[1]++;
    }
    if (cnt[0] + cnt[1] == n && std::abs(cnt[0] - cnt[1]) < 2) {
        std::cout << "Yes\n";
        return;
    }
    std::sort(a.begin() + 1, a.end(), [](int x, int y) {
        return std::abs(x) < std::abs(y);
        });
    for (int i = 2; i <= n - 1;i++)
        if (a[i] * a[i] != a[i - 1] * a[i + 1])
        {
            std::cout << "No\n";
            return;
        }
    std::cout << "Yes\n";
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