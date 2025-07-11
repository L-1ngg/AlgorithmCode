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
const int inf = (1 << 31) - 1;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector adj(n + 1, std::vector<pii>());
    for (int i = 1;i <= m;i++) {
        int u, v, w;    std::cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }

    auto dij = [&](int root) {
        std::vector<int> d(n + 1, inf), vis(n + 1, 0);
        d[root] = 0;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        pq.push({ 0,root });

        while (pq.size()) {
            auto [curmax, u] = pq.top();
            pq.pop();

            if (vis[u]) continue;
            vis[u] = 1;

            for (auto [v, w] : adj[u]) {
                if (std::max(curmax, w) < d[v]) {
                    d[v] = std::max(curmax, w);
                    pq.push({ d[v],v });
                }
            }
        }
        return d;
        };

    std::vector<int> dis1 = dij(1), dis2 = dij(n);

    int ans = inf;
    for (int u = 1;u <= n;u++)
        for (auto [v, w] : adj[u]) {
            ans = std::min(ans, std::max({ dis1[u], dis2[v], w }) + w);
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