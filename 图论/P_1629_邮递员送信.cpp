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
    int n, m;    std::cin >> n >> m;
    std::vector<std::vector<pii>> adj[2];
    adj[0].resize(n + 1);
    adj[1].resize(n + 1);
    for (int i = 1;i <= m;i++) {
        int u, v, w;    std::cin >> u >> v >> w;
        adj[0][u].push_back({ v,w });
        adj[1][v].push_back({ u,w });
    }

    auto dijkstra = [&](int f) ->i64 {
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        std::vector<i64> vis(n + 1, 0), dis(n + 1, inf);
        pq.push({ 0,1 });
        dis[1] = 0;
        while (!pq.empty())
        {
            auto [_, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w] : adj[f][u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({ dis[v],v });
                }
            }
        }
        return std::accumulate(dis.begin() + 1, dis.end(), 0ll);
        };
    std::cout << dijkstra(0) + dijkstra(1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}