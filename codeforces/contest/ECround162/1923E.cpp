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
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)    std::cin >> a[i];

    std::vector<std::map<int, int>> b(n + 1);
    std::vector adj(n + 1, std::vector<int>());
    for (int i = 1;i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    i64 ans = 0;
    auto dfs = [&](auto&& self, int u, int fa)->void {
        for (auto v : adj[u])
        {
            if (v == fa)    continue;
            self(self, v, u);
            if (b[v].count(a[u])) ans += b[v][a[u]];

            if (b[v].size() > b[u].size()) std::swap(b[u], b[v]);
            for (auto [x, y] : b[v])
            {
                if (b[u].count(x) && a[u] != x) ans += (i64)y * b[u][x];
                b[u][x] += y;
            }
        }
        b[u][a[u]] = 1;
        };
    dfs(dfs, 1, 1);
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}