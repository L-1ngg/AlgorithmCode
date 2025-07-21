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

void solve() {
    int n, q;   std::cin >> n >> q;
    std::vector<int> col(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> col[i];
    std::map<int, pii> adj[n + 1];
    std::map<int, i64> res[n + 1];
    std::vector<int> upd[n + 1];
    std::vector<int> con[n + 1];

    i64 ans = 0;
    // std::cout << res[2][1] << '\n';
    for (int i = 1;i <= n - 1;i++) {
        int u, v, w;    std::cin >> u >> v >> w;
        adj[u][v] = { w,col[v] };
        adj[v][u] = { w,col[u] };

        if (col[u] != col[v])   ans += w;
        res[u][col[v]] += w;
        res[v][col[u]] += w;

        con[v].push_back(u);
        con[u].push_back(v);
    }

    while (q--) {
        int u, y;   std::cin >> u >> y;

        if (upd[u].size()) {
            for (auto v : upd[u])
            {
                int tmpcol = adj[u][v].second;
                adj[u][v].second = col[v];
                if (tmpcol != col[v]) {
                    if (!(res[u][tmpcol] -= adj[u][v].first)) res[u].erase(tmpcol);
                    res[u][col[v]] += adj[u][v].first;
                }

                con[v].push_back(u);
            }
        }
        upd[u].clear();

        for (auto v : con[u])
            upd[v].push_back(u);
        con[u].clear();

        ans -= res[u][y];
        ans += res[u][col[u]];
        col[u] = y;
        std::cout << ans << '\n';
    }
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