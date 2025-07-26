#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<i64, 2>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, c;   std::cin >> n >> c;
    std::vector adj(n + 1, std::vector<int>());
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    adj[0].push_back(1);
    std::vector<a2> f(n + 1);
    auto dfs = [&](auto&& self, int u, int fa)->void {
        f[u][1] = a[u];
        for (auto v : adj[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            f[u][0] += std::max(f[v][1], f[v][0]);
            f[u][1] += std::max(f[v][1] - 2 * c, f[v][0]);
        }
        };
    dfs(dfs, 1, 0);
    // std::cout << f[1][0] << '\n';
    std::cout << std::max(f[1][1], f[1][0]) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}