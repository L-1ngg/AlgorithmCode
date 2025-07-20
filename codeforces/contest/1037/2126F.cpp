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

struct node {
    std::map<int, i64> num;
    int col;
    std::map<int, int> adj;
    std::set<int> con;
    std::set<a3> upd;
};
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<node> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i].col;

    i64 ans = 0;
    for (int i = 1;i <= n - 1;i++) {
        int u, v, w;    std::cin >> u >> v >> w;
        a[u].adj[v] = w;
        a[u].num[a[v].col] += w;
        a[u].con.insert(v);

        a[v].adj[u] = w;
        a[v].num[a[u].col] += w;
        a[v].con.insert(u);

        if (a[u].col != a[v].col) ans += w;
    }

    auto cal = [&](int x, int col) {
        for (auto [v, old, w] : a[x].upd) {
            a[x].num[old] -= w;
            if (a[x].num[old] == 0) a[x].num.erase(old);
            a[x].num[a[v].col] += w;

            a[v].con.insert(x);
        }
        a[x].upd.clear();
        for (auto v : a[x].con) {
            a[v].upd.insert({ x,a[x].col, a[x].adj[v] });
        }
        a[x].con.clear();

        };
    while (q--) {
        int x, col; std::cin >> x >> col;
        if (a[x].col != col) {
            cal(x, col);
            ans -= a[x].num[col];
            ans += a[x].num[a[x].col];
            a[x].col = col;
        }
        std::cout << ans << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}