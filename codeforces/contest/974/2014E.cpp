#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
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
    int n, m, h;    std::cin >> n >> m >> h;
    std::vector adj(n + 1, std::vector<pii>());
    std::vector<int> v(n + 1);
    for (int i = 1;i <= h;i++) {
        int x;  std::cin >> x;
        v[x] = 1;
    }
    for (int i = 1;i <= m;i++) {
        int u, v, w;   std::cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }

    auto dij = [&](int root) {
        std::vector<i64> dis(n + 1, INF);
        std::vector<a2> vis(n + 1);

        dis[root] = 0;
        std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
        pq.push({ 0,root,0 });

        while (pq.size()) {
            auto [d, u, st] = pq.top();
            pq.pop();
            if (v[u]) st = 1;
            if (vis[u][st])  continue;
            vis[u][st] = 1;

            for (auto [v, w] : adj[u]) {
                int t = (st == 1 ? w / 2 : w);
                if (d + t < dis[v]) {
                    dis[v] = d + t;
                }
                pq.push({ d + t,v,st });
            }
        }
        return dis;
        };

    auto dis1 = dij(1), dis2 = dij(n);
    i64 ans = INF;
    for (int i = 1;i <= n;i++)
        ans = std::min(ans, std::max(dis1[i], dis2[i]));
    std::cout << (ans == INF ? -1 : ans) << '\n';
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