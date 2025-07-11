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
    int n, k;   std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n * k);
    for (int i = 1; i <= n * k - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto&& self, int x, int p = -1) -> int {
        int cnt = 0;
        int sum = 0;
        for (auto y : adj[x])
        {
            if (y == p) continue;
            int tmp = self(self, y, x);
            if (tmp == -1)
                return -1;
            else if (tmp > 0)
            {
                cnt++;
                sum += tmp;
            }
        }
        if (cnt > 2) return -1;
        else if (sum == k - 1)  return 0;
        else if (cnt == 2)  return -1;
        else return sum + 1;
        };

    if (dfs(dfs, 0, -1) == 0)
        std::cout << "Yes";
    else std::cout << "No";
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