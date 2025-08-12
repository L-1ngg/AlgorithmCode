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
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector adj(n + 1, std::vector<int>());
    std::vector<int> d(n + 1);
    for (int i = 1;i <= n - 1;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++;
        d[v]++;
    }

    std::vector<i64> sz(n + 1, 0);
    std::vector<i64> num(n + 1, 0);
    int cnt = 0;
    auto dfs = [&](auto&& self, int u, int fa)->void {
        sz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            sz[u]++;
            if (sz[v] == 1) num[u]++;
        }
        if (sz[u]) cnt++;
        };
    int st = 1;
    for (int i = 1;i <= n;i++)
        if (d[i] > 1) st = i;
    dfs(dfs, st, 0);
    int mx = *std::max_element(num.begin(), num.end());
    if (cnt == 1)std::cout << 0;
    else std::cout << std::accumulate(num.begin(), num.end(), 0ll) - mx;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}