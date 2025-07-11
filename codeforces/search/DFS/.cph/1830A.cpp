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
    for (int i = 1;i <= n - 1;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back({ v,i });
        adj[v].push_back({ u,i });
    }

    int ans = 0;
    auto dfs = [&](auto&& self, int u, int fa, int time, int cost)->void {
        ans = std::max(ans, cost);
        for (auto [v, t] : adj[u]) {
            if (v == fa) continue;
            // if (t < cost) std::cout << v << " " << u << '\n';
            self(self, v, u, t, cost + (t < time));
        }
        };
    dfs(dfs, 1, 0, 0, 1);
    std::cout << ans << '\n';
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