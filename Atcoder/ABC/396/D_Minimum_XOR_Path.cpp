#include <bits/stdc++.h>
using i64 = long long;

const int N = 400;
const i64 inf = 9114511145141919810;

int nex[N], head[N], to[N], cnt;
i64 wei[N];
int vis[N];

void add(int u, int v, i64 w)
{
    nex[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    wei[cnt] = w;
}

void solve()
{
    int n, m;   std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; i64 w;
        std::cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    i64 ans = inf;
    auto dfs = [&](auto&& self, int u, i64 res) -> void
        {
            if (u == n)
            {
                ans = std::min(ans, res);
                return;
            }
            for (int i = head[u];i;i = nex[i])
            {
                int v = to[i];
                if (vis[v]) continue;
                vis[v] = 1;
                self(self, v, res ^ wei[i]);
                vis[v] = 0;
            }
        };
    vis[1] = 1;
    dfs(dfs, 1, 0);
    std::cout << ans;
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}