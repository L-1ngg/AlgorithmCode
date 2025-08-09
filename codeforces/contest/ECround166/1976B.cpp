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
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1), b(n + 2);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n + 1;i++)   std::cin >> b[i];
    int num = inf;
    i64 ans = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] > b[i]) std::swap(a[i], b[i]);
        if (b[n + 1] >= a[i] && b[n + 1] <= b[i]) num = 0;
        else num = std::min({ num,std::abs(a[i] - b[n + 1]),std::abs(b[i] - b[n + 1]) });
        ans += b[i] - a[i];
    }
    std::cout << ans + num + 1;
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