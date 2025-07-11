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
    int n;  std::cin >> n;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n;i++) std::cin >> a[i];
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1;i <= n - 1;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<i64> mx(n + 1), mn(n + 1);
    std::vector<int> vis(n + 1, 0);
    auto dfs = [&](auto&& self, int u) ->void {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (vis[v]) continue;
            mx[v] = std::max(a[v], a[v] - mn[u]);
            mn[v] = std::min(a[v], a[v] - mx[u]);
            self(self, v);
        }
        };
    mx[1] = mn[1] = a[1];
    dfs(dfs, 1);
    for (int i = 1;i <= n;i++)
        std::cout << mx[i] << " \n"[i == n];
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