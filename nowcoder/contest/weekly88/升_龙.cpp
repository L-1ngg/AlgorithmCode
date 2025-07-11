#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

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
    int n, q;   std::cin >> n >> q;
    std::vector<int> v(n + 1), fa(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> v[i];

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2;i <= n;i++)
    {
        std::cin >> fa[i];
        g[fa[i]].push_back(i);
    }

    //dfn:访问次序,dp表示子树的最大权值
    std::vector<int> pre(n + 1);
    std::vector<int> dfn(n + 1), dp(n + 1, 0);
    std::vector<int> L(n + 1), R(n + 1), leaf(n + 1);
    int cnt = 0;

    auto dfs = [&](auto&& self, int u) -> int {
        pre[u] = pre[fa[u]] + v[u];
        L[u] = u, R[u] = u;

        if (g[u].size() == 0)
        {
            dfn[u] = ++cnt;
            leaf[cnt] = u;
            return dp[u] = v[u];
        }

        for (auto nex : g[u])
            dp[u] = std::max(dp[u], self(self, nex) + v[u]);
        L[u] = L[g[u][0]];
        R[u] = R[g[u].back()];
        return dp[u];
        };

    dfs(dfs, 1);
    std::vector<int> pre_mx(cnt + 1, 0), suf_mx(cnt + 2, 0);
    for (int i = 1; i <= cnt;i++)
        pre_mx[i] = std::max(pre_mx[i - 1], pre[leaf[i]]);
    for (int i = cnt;i >= 1;i--)
        suf_mx[i] = std::max(suf_mx[i + 1], pre[leaf[i]]);

    while (q--)
    {
        int x, y;   std::cin >> x >> y;
        int l = dfn[L[x]], r = dfn[R[x]];
        int ans = std::max(pre_mx[l - 1], suf_mx[r + 1]);
        ans = std::max(ans, pre[fa[x]]);
        ans = std::max(ans, pre[y] + dp[x]);
        std::cout << ans << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}