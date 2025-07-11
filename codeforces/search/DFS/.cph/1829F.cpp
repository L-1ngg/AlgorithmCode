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
    int n, m;   std::cin >> n >> m;
    std::vector adj(n + 1, std::vector<int>());
    std::vector<int> d(n + 1, 0);
    for (int i = 1; i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }

    auto dfs = [&](auto&& self, int u, int fa) {
        for (auto v : adj[u]) {
            if (v == fa || d[v] == 1) continue;
            if (d[v] != 1 && d[u] != 1) {
                std::cout << d[v] << " " << d[u] - 1 << '\n';
                return;
            }
            self(self, v, u);
        }
        };
    for (int i = 1;i <= n;i++)
        if (d[i] == 1)
        {
            dfs(dfs, i, 0);
            return;
        }
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