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
    int n, q;   std::cin >> n >> q;
    std::map<std::string, int> to;
    to["BR"] = 1;
    to["BG"] = 2;
    to["BY"] = 3;
    to["GR"] = 4;
    to["RY"] = 5;
    to["GY"] = 6;
    std::vector a(7, std::vector<int>());
    std::vector<int> b(n + 1);
    for (int i = 1;i <= n;i++)
    {
        std::string s;  std::cin >> s;
        b[i] = to[s];
        a[b[i]].push_back(i);
    }
    while (q--) {
        int x, y;   std::cin >> x >> y;
        if (x > y) std::swap(x, y);
        if (b[x] + b[y] != 7) {
            std::cout << y - x << '\n';
            continue;
        }

        int f = 0, ans = inf;
        for (int i = 1;i <= 6;i++)
        {
            if (f) break;
            if (i == b[x] || i == b[y]) continue;
            auto it = std::lower_bound(a[i].begin(), a[i].end(), x);
            if (it != a[i].end() && *it <= y) {
                std::cout << y - x << '\n';
                f = 1;
                continue;
            }
            else if (it != a[i].end()) ans = std::min(ans, *it - y + *it - x);

            auto rit = std::lower_bound(a[i].rbegin(), a[i].rend(), y, std::greater<>());
            if (rit != a[i].rend() && *rit >= x) {
                std::cout << y - x << '\n';
                f = 1;
                continue;
            }
            else if (rit != a[i].rend()) ans = std::min(ans, x - *rit + y - *rit);
        }
        if (!f) std::cout << (ans == inf ? -1 : ans) << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}