#include <bits/stdc++.h>
using namespace std;
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

struct EDCC {
    int n, m, now, cnt;
    vector<vector<array<int, 2>>> ver;
    vector<int> dfn, low, col, S, sz;
    set<array<int, 2>> bridge, direct; // 如果不需要，删除这一部分可以得到一些时间上的优化

    EDCC(int n) : n(n), low(n + 1), ver(n + 1), dfn(n + 1), col(n + 1), sz(n + 1) {
        m = now = cnt = 0;
    }
    void add(int x, int y) { // 和 scc 相比多了一条连边
        ver[x].push_back({ y, m });
        ver[y].push_back({ x, m++ });
    }
    void tarjan(int x, int fa) {
        dfn[x] = low[x] = ++now;
        S.push_back(x);
        sz[x] = 1;
        for (auto& [y, id] : ver[x]) {
            if (!dfn[y]) {
                direct.insert({ x, y });
                tarjan(y, id);
                low[x] = min(low[x], low[y]);
                if (dfn[x] < low[y]) {
                    bridge.insert({ x, y });
                }
                sz[x] += sz[y];
            }
            else if (id != fa && dfn[y] < dfn[x]) {
                direct.insert({ x, y });
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            int pre;
            cnt++;
            do {
                pre = S.back();
                col[pre] = cnt;
                S.pop_back();
            } while (pre != x);
        }
    }
    auto work() {
        for (int i = 1; i <= n; i++) { // 避免图不连通
            if (!dfn[i]) {
                tarjan(i, 0);
            }
        }
        vector<int> siz(cnt + 1);
        vector<vector<int>> adj(cnt + 1);
        for (int i = 1; i <= n; i++) {
            siz[col[i]]++;
            for (auto& [j, id] : ver[i]) {
                int x = col[i], y = col[j];
                if (x != y) {
                    adj[x].push_back(y);
                }
            }
        }
        return tuple{ cnt, adj, col, siz };
    }
};


void solve()
{
    int n, m;   std::cin >> n >> m;
    EDCC e(n);
    for (int i = 1;i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        e.add(u, v);
    }
    e.work();
    i64 ans = INF;
    for (auto [x, y] : e.bridge) {
        ans = std::min(ans, (i64)e.sz[y] * (e.sz[y] - 1) / 2 + (i64)(n - e.sz[y]) * (n - e.sz[y] - 1) / 2);
    }

    std::cout << (ans == INF ? (i64)n * (n - 1) / 2 : ans) << '\n';
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