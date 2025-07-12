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

std::vector<int> fa;
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void solve()
{
    int n, m;   std::cin >> n >> m;
    fa.assign(n + 1, 0);
    std::iota(fa.begin(), fa.end(), 0);
    std::vector<std::set<int>> adj(n + 1);
    std::vector<pii> e(m + 1);

    for (int i = 1;i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        e[i].first = u, e[i].second = v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int q;  std::cin >> q;
    while (q--) {
        int id; std::cin >> id;
        auto [u, v] = e[id];
        u = find(u), v = find(v);
        if (u == v) {
            std::cout << m << "\n";
            continue;
        }
        int szu = adj[u].size(), szv = adj[v].size();
        if (szu < szv)   std::swap(u, v);
        for (auto to : adj[v]) {
            adj[to].erase(v);
            m--;
            if (to != u && !adj[u].count(to)) {
                adj[u].insert(to);
                adj[to].insert(u);
                m++;
            }
        }
        fa[v] = u;
        adj[v].clear();
        std::cout << m << "\n";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}