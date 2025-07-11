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
    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1;i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1;i <= n;i++) ranges::sort(adj[i]);

    std::vector<int> f;
    f.assign(n + 1, 0);
    auto dfs = [&](auto&& self, int p) -> void {
        f[p] = 1;
        std::cout << p << " ";
        for (auto x : adj[p]) {
            if (!f[x])  self(self, x);
        }
        };
    dfs(dfs, 1);
    std::cout << '\n';

    f.assign(n + 1, 0);
    auto bfs = [&]() {
        std::queue<int> tmp;
        tmp.push(1), f[1] = 1;
        while (!tmp.empty()) {
            auto u = tmp.front();
            tmp.pop();
            std::cout << u << " ";
            for (auto x : adj[u]) if (!f[x]) tmp.push(x), f[x] = 1;
        }
        };
    bfs();
    std::cout << '\n';
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