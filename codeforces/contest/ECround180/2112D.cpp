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
    std::vector adj(n + 1, std::vector<int>());
    std::vector<int> d(n + 1);
    for (int i = 1;i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }
    int has2 = 0;
    for (int i = 1;i <= n;i++) if (d[i] == 2) has2 = i;
    if (!has2) {
        std::cout << "NO\n";
        return;
    }
    std::vector<int> vis(n + 1, 0);
    auto dfs = [&](auto&& self, int u, int fa, int f)->void {
        if (vis[u]) return;
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (v == fa) continue;
            if (f)   std::cout << v << " " << u << '\n';
            else std::cout << u << " " << v << '\n';
            self(self, v, u, f ^ 1);
        }
        };
    std::cout << "YES\n";
    std::cout << has2 << " " << adj[has2][0] << '\n';
    std::cout << adj[has2][1] << " " << has2 << '\n';
    dfs(dfs, adj[has2][0], has2, 1);
    dfs(dfs, adj[has2][1], has2, 0);
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