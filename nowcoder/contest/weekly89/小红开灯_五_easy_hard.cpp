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
    int n;  std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n;i++) {
        int u, v;   std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<pii> ans;
    std::vector<int> vis(n + 1);
    auto dfs = [&](auto&& self, int u, int fa) -> void {
        int f = 0, pos = 0;
        for (auto x : g[u]) {
            if (x == fa)     continue;
            self(self, x, u);
            if (!vis[x]) {
                pos = x;
                f = 1;
            }
        }

        if (f && vis[u] == 0) {
            if (fa == 0 || vis[fa] == 1) {
                ans.push_back({ u,pos });
                vis[u] = vis[pos] = 1;
            }
            else {
                ans.push_back({ u,fa });
                vis[u] = vis[fa] = 1;
            }
        }
        };

    dfs(dfs, 1, 0);
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        std::cout << x << ' ' << y << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}