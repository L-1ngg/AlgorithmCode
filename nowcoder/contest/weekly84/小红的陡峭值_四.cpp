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
    std::vector<std::vector<int>> adj(n + 1);

    i64 total = 0;
    for (int i = 1; i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        total += std::abs(u - v);
    }

    i64 mn = INF;
    auto dfs = [&](auto&& self, int u, int fa) -> i64
        {
            i64 sum = 0;
            for (auto v : adj[u])
            {
                if (v == fa)   continue;
                i64 d = std::abs(u - v);
                i64 tmp = self(self, v, u);
                mn = std::min(mn, std::abs(total - (d + tmp) - tmp));
                sum += tmp + d;
            }
            return sum;
        };

    dfs(dfs, 1, 0);
    std::cout << mn << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}