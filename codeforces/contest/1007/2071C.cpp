#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

void solve()
{
    int n, st, en;  std::cin >> n >> st >> en;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::vector<int>> dis(n + 1);
    std::vector<int> d(n + 1, 0);
    int mx = 0;

    auto dfs = [&](auto&& self, int pos, int pre)->void
        {
            d[pos] = d[pre] + 1;
            mx = std::max(mx, d[pos]);
            dis[d[pos]].push_back(pos);
            for (auto u : adj[pos])
            {
                if (u == pre) continue;
                self(self, u, pos);
            }
        };

    dfs(dfs, en, 0);
    for (int i = mx;i >= 1; i--)
    {
        for (auto u : dis[i])
            std::cout << u << ' ';
    }
    std::cout << '\n';
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