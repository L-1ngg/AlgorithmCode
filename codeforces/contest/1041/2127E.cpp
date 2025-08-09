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
    int n, k;   std::cin >> n >> k;
    std::vector<int> w(n + 1), c(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> w[i];
    for (int i = 1;i <= n;i++)   std::cin >> c[i];


    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1;i <= n - 1;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    i64 ans = 0;
    auto down = [&](this auto&& self, int u, int p) ->void {
        c[u] = c[p];
        for (auto v : adj[u])
        {
            if (v == p)continue;
            self(v, u);
        }
        };

    std::vector<std::set<int>> s(n + 1);
    auto dfs = [&](this auto&& self, int u, int p) ->void {
        std::vector<int> a;
        for (auto v : adj[u]) {
            if (v == p) continue;
            self(v, u);
            if (s[u].size() < s[v].size())
                std::swap(s[u], s[v]);
            for (int x : s[v])
            {
                if (s[u].count(x))  a.push_back(x);
                else s[u].insert(x);
            }
        }
        std::sort(a.begin(), a.end());
        a.erase(std::unique(a.begin(), a.end()), a.end());

        if (a.size() >= 2 || (a.size() == 1 && c[u] && c[u] != a[0]))
            ans += w[u];
        if (c[u])   s[u].insert(c[u]);
        else if (a.size()) c[u] = a[0];
        else if (s[u].size()) c[u] = *s[u].begin();
        if (c[u])
            for (auto v : adj[u])
            {
                if (v == p)  continue;
                if (!c[v]) down(v, u);
            }
        };
    dfs(1, 1);
    for (int i = 1;i <= n;i++)
        if (!c[i]) c[i] = 1;

    std::cout << ans << '\n';
    for (int i = 1;i <= n;i++)
        std::cout << c[i] << " ";
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