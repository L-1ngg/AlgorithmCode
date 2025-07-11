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
    for (int i = 1;i <= n;i++)  std::cin >> a[i];

    int x = a[1], y = a[n], ans = 2;
    std::sort(a.begin() + 1, a.end());
    while (x * 2 < y) {
        int p = std::upper_bound(a.begin(), a.end(), x * 2) - a.begin() - 1;
        if (a[p] == x) {
            std::cout << "-1";
            return;
        }
        x = a[p];
        ans++;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}