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
    int l, r;   std::cin >> l >> r;
    std::vector<int> a, b;
    while (l) {
        a.push_back(l % 10);
        l /= 10;
        b.push_back(r % 10);
        r /= 10;
    }
    int n = a.size();
    n--;

    int ans = 0;
    int x = 0, y = 0;
    for (int i = n;i >= 0;i--) {
        x = x * 10 + a[i];
        y = y * 10 + b[i];
        if (x == y) ans += 2;
        else if (std::abs(x - y) == 1) ans += 1;
        else break;
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