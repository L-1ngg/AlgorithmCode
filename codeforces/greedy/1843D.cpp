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

void solve()
{
    int n;  std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int l, r;   std::cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    std::vector<int> cnt(n + 1, 0);
    auto dfs = [&](this auto&& self, int x, int pre) ->int
        {
            if (adj[x].size() == 1 && x != 1)
            {
                cnt[x] = 1;
                return 1;
            }

            for (auto v : adj[x])
            {
                if (v == pre)
                    continue;
                cnt[x] += self(v, x);
            }
            return cnt[x];
        };

    dfs(1, 0);
    int q;  std::cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;   std::cin >> x >> y;
        std::cout << (i64)cnt[x] * cnt[y] << '\n';
    }
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