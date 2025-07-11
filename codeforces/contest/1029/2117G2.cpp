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

//min记录了每个连通分量的最小权值
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<a3> e(m + 1);
    for (int i = 1;i <= m;i++) {
        int u, v, w;    std::cin >> u >> v >> w;
        e[i] = { w,u,v };
    }
    std::sort(e.begin() + 1, e.end());
    std::vector<int> fa(n + 1), min(n + 1, inf);
    std::iota(fa.begin(), fa.end(), 0);
    auto find = [&](auto&& self, int x) -> int {
        return fa[x] = (x == fa[x] ? x : self(self, fa[x]));
        };

    int ans = 2e9;
    for (int i = 1;i <= m;i++) {
        int u = find(find, e[i][1]), v = find(find, e[i][2]);
        if (u == v) continue;
        fa[u] = v, min[v] = std::min({ min[u],min[v] ,e[i][0] });
        if (find(find, 1) == find(find, n)) {
            ans = std::min(ans, e[i][0] + min[find(find, 1)]);
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
