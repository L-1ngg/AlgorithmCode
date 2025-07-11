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

std::vector<int> f, size, w;
std::vector<std::vector<int>> adj;

void dfs(int u, int fa, int dep) {
    size[u] = w[u];
    for (auto v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u, dep + 1);
        size[u] += size[v];
    }
    f[1] += w[u] * dep;
}

void dp(int u, int fa) {
    for (auto v : adj[u])
    {
        if (v == fa) continue;
        f[v] = f[u] - size[v] + size[1] - size[v];
        dp(v, u);
    }
}

void solve()
{
    int n;  std::cin >> n;
    w.assign(n + 1, 0);
    size.assign(n + 1, 0);
    f.assign(n + 1, 0);
    adj.assign(n + 1, std::vector<int>());

    for (int i = 1;i <= n;i++) {
        int x, l, r;    std::cin >> x >> l >> r;
        w[i] = x;
        if (l) {
            adj[i].push_back(l);
            adj[l].push_back(i);
        }
        if (r) {
            adj[i].push_back(r);
            adj[r].push_back(i);
        }
    }

    dfs(1, 0, 0);
    dp(1, 0);

    // std::cout << f[2];
    std::cout << *min_element(f.begin() + 1, f.end());
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