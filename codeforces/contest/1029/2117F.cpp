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

i64 qpow(i64 x, i64 b) {
    i64 ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}
void solve()
{
    int n;  std::cin >> n;
    std::vector e(n + 1, std::vector<int>());
    std::vector<int> d(n + 1), leaf, dep(n + 1);
    for (int i = 1;i <= n - 1;i++) {
        int u, v;   std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        d[u]++, d[v]++;
    }
    for (int i = 2;i <= n;i++)
        if (d[i] == 1)
            leaf.push_back(i);

    if (leaf.size() == 1)
    {
        std::cout << qpow(2, n);
        return;
    }
    if (leaf.size() >= 3) {
        std::cout << 0;
        return;
    }

    auto dfs = [&](auto&& self, int u, int fa)->void {
        dep[u] = dep[fa] + 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }
        };

    dep[0] = 0;
    dfs(dfs, 1, 0);
    int lca = 1;
    for (int i = 2;i <= n;i++) if (d[i] == 3) lca = i;
    int len1 = dep[leaf[0]] - dep[lca];
    int len2 = dep[leaf[1]] - dep[lca];
    if (len1 == len2)    std::cout << qpow(2, n - 2 * len1 + 1);
    else std::cout << qpow(2, n - std::min(len1, len2) * 2 - 1) * 3 % mod;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
}