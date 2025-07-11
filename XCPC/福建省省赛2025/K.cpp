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
    std::vector adj(n + 1, std::vector<pii>());
    int mx = 0;
    for (int i = 1;i <= n - 1;i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (u == 1 || v == 1) mx = std::max(mx, w);
        adj[v].push_back({ u,w });
        adj[u].push_back({ v,w });
    }
    std::vector<int> dph(n + 1, 0);
    std::vector<i64> f(n + 1, 0);
    auto dfs = [&](auto&& self, int u, int fa)->void {
        dph[u] = dph[fa] + 1;
        for (auto [v, w] : adj[u])
        {
            if (v == fa) continue;
            f[v] = w - f[u];
            self(self, v, u);
        }
        };
    dfs(dfs, 1, 0);

    i64 l = 1, r = mx;
    for (int i = 2;i <= n;i++)
    {
        if (dph[i] & 1) l = std::max(l, 1 - f[i]);
        else r = std::min(r, f[i] - 1);
    }
    if (l <= r) {
        std::cout << "YES\n";
        std::cout << l << " ";
        for (int i = 2;i <= n;i++)
        {
            if (dph[i] & 1) std::cout << f[i] + l << " ";
            else std::cout << f[i] - l << " ";
        }
    }
    else    std::cout << "NO";
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