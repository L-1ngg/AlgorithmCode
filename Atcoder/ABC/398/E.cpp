#include <bits/stdc++.h>
void solve()
{
    int n;  std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);
    int vis[105][105] = { 0 };
    for (int i = 1; i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        vis[u][v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<std::vector<int>> V(2);
    auto dfs = [&](auto&& self, int p, int fa, int f)-> void
        {
            V[f ^ 1].push_back(p);
            for (auto v : adj[p])
            {
                if (v == fa)  continue;
                self(self, v, p, f ^ 1);
            }
        };
    dfs(dfs, 1, -1, 1);

    if ((V[0].size() * V[1].size() - (n - 1)) & 1)
        std::cout << "First" << std::endl;
    else {
        std::cout << "Second" << std::endl;
        int u, v;   std::cin >> u >> v;
        if (u == -1) return;
        vis[u][v] = 1;
    }

    for (auto i : V[0])
        for (auto j : V[1])
        {
            if (vis[i][j])   continue;
            vis[i][j] = vis[j][i] = 1;
            std::cout << std::min(i, j) << ' ' << std::max(i, j) << std::endl;
            int u, v;   std::cin >> u >> v;
            if (u == -1) return;
            vis[u][v] = 1;
        }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}
