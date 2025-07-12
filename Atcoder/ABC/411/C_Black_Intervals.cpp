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
    int n, q;   std::cin >> n >> q;
    std::vector<int> a(n + 2);
    int ans = 0;
    while (q--) {
        int x;  std::cin >> x;
        if (a[x] == 0) {
            if (a[x - 1] == 0 && a[x + 1] == 0) ans++;
            if (a[x - 1] == 1 && a[x + 1] == 1) ans--;
        }
        else {
            if (a[x - 1] == 0 && a[x + 1] == 0) ans--;
            if (a[x - 1] == 1 && a[x + 1] == 1) ans++;
        }
        a[x] = 1 - a[x];
        std::cout << ans << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}