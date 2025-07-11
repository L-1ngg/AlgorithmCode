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
const int mod = 1e9 + 7;
const i64 MOD = 9114511145141919810;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 2>>> adj(n + 1);
    for (int i = 1; i <= m;i++)
    {
        int u, v, w;    std::cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }

    std::vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != -1)    continue;
        std::vector<int> vis{ i }; // record path
        int cnt[30]{}; //record K-th the number of 1

        ans[i] = 0;
        for (int j = 0; j < vis.size();j++)
        {
            int x = vis[j];
            for (int t = 0; t < 30;t++) {
                cnt[t] += ans[x] >> t & 1;
            }
            for (auto [v, w] : adj[x])
            {
                if (ans[v] == -1)
                {
                    ans[v] = w ^ ans[x];
                    vis.push_back(v);
                }
                else if (ans[v] != (ans[x] ^ w))
                {
                    std::cout << "-1";
                    return;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 30; j++)
            if (cnt[j] > vis.size() / 2)
                res |= 1 << j;

        for (auto x : vis)
            ans[x] ^= res;
    }
    for (int i = 1; i <= n; i++)
        std::cout << ans[i] << ' ';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}