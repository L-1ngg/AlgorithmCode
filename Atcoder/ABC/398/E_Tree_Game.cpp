#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 110;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::bitset<N> col;
int cntw;
void solve()
{
    int n;  std::cin >> n;
    int vis[N][N] = { 0 };
    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 1; i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        vis[u][v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](auto&& self, int p, int fa)-> void
        {
            cntw += col[p];
            for (auto v : adj[p])
            {
                if (v == fa)  continue;
                col[v] = col[p] ^ 1;
                self(self, v, p);
            }
        };
    bfs(bfs, 1, -1);

    if ((cntw * (n - cntw) - (n - 1)) & 1)
        std::cout << "First" << std::endl;
    else {
        std::cout << "Second" << std::endl;
        int u, v;   std::cin >> u >> v;
        if (u == -1) return;
        vis[u][v] = 1;
    }

    for (int i = 1; i < n;i++)
        for (int j = i + 1;j <= n;j++)
        {
            if (vis[i][j] || col[i] == col[j])   continue;
            std::cout << i << ' ' << j << std::endl;
            int u, v;   std::cin >> u >> v;
            if (u == -1) {
                return;
            }
            vis[u][v] = 1;
        }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}