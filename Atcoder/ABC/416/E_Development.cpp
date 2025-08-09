#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
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
    int n, m;   std::cin >> n >> m;
    std::vector d(n + 1, std::vector<int>(n + 1));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            d[i][j] = (i == j ? 0 : INF);

    auto add = [&](int u, int v, int w) {
        d[u][v] = std::min(d[u][v], w);
        d[v][u] = std::min(d[v][u], w);
        };

    for (int i = 1;i <= m;i++)
    {
        int u, v, w;    std::cin >> u >> v >> w;
        add(u, v, w);
    }

    int k, t;   std::cin >> k >> t;
    std::vector<int> dis(n + 1, INF);
    std::vector<int> air;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    for (int i = 1;i <= k;i++)
    {
        int x;  std::cin >> x;
        air.push_back(x);
        dis[x] = 0;
        pq.push({ 0,x });
    }

    auto dij = [&]() {
        while (pq.size()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist != dis[u]) continue;
            for (int i = 1;i <= n;i++)
                if (dis[i] > dist + d[u][i])
                {
                    dis[i] = dist + d[u][i];
                    pq.push({ dis[i],i });
                }
        }
        };

    auto floyd = [&]() {
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
        };

    floyd();
    dij();

    int q;  std::cin >> q;
    while (q--) {
        int op;     std::cin >> op;
        if (op == 1) {
            int u, v, w;    std::cin >> u >> v >> w;
            if (w < d[u][v]) {
                d[u][v] = d[v][u] = w;
                for (int i = 1;i <= n;i++)
                    for (int j = 1;j <= n;j++)
                        d[i][j] = std::min(d[i][j], d[i][u] + d[u][j]);
                for (int i = 1;i <= n;i++)
                    for (int j = 1;j <= n;j++)
                        d[i][j] = std::min(d[i][j], d[i][v] + d[v][j]);
            }
            for (auto x : air) pq.push({ 0,x });
            dij();
        }
        else if (op == 2) {
            int x;  std::cin >> x;
            dis[x] = 0;
            air.push_back(x);
            pq.push({ 0,x });
            dij();
        }
        else {
            int ret = 0;
            // std::cout << dis[2] << '\n';
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                {
                    int tmp = std::min(d[i][j], dis[i] + dis[j] + t);
                    if (tmp < INF) ret += tmp;
                }
            std::cout << ret << '\n';
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}