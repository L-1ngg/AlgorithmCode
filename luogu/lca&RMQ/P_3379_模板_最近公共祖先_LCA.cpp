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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, root; std::cin >> n >> m >> root;

    std::vector<std::vector<int>> e(n + 1);
    for (int i = 1; i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> dep(n + 1, 0);
    std::vector<std::vector<int>> father(n + 1, std::vector<int>(20, 0));

    auto dfs = [&](auto self, int u, int fa) ->void
        {
            dep[u] = dep[fa] + 1;
            father[u][0] = fa;
            for (int i = 1; i <= 19;i++)
                father[u][i] = father[father[u][i - 1]][i - 1];
            for (auto v : e[u])
                if (v != fa)
                    self(self, v, u);
        };

    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v])
            std::swap(u, v);

        for (int i = 19; i >= 0;i--)
        {
            if (dep[father[u][i]] >= dep[v])
                u = father[u][i];
        }
        if (u == v) return v;
        for (int i = 19; i >= 0;i--)
            if (father[u][i] != father[v][i])
                u = father[u][i], v = father[v][i];
        return father[u][0];
        };

    dfs(dfs, root, 0);
    for (int i = 1; i <= m;i++)
    {
        int u, v;   std::cin >> u >> v;
        std::cout << lca(u, v) << '\n';
    }

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