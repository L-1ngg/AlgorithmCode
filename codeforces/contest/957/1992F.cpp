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
    int n, x;   std::cin >> n >> x;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    std::set<int> vis;
    for (int i = 2;i <= x / i;i++) {
        if (x % i != 0) continue;
        vis.insert(i);
        if (x / i != i)     vis.insert(x / i);
    }

    int ans = 1;
    std::set<int> now;
    for (int i = 1;i <= n;i++) {
        if (!vis.count(a[i])) continue;
        if (now.count(x / a[i])) {
            ans++;
            now.clear();
            now.insert(a[i]);
        }
        else {
            std::set<int> tmp;
            for (auto d : vis) {
                if (now.count(d) && vis.count(d * a[i]))
                    tmp.insert(d * a[i]);
            }
            tmp.insert(a[i]);
            for (auto t : tmp)  now.insert(t);
        }
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