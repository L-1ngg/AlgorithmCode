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

struct edge {
    int v, w;
};
std::vector<std::vector<edge>> e;
std::vector<int> dis, cnt, vis;
std::queue<int> q;

bool spfa(int n, int s) {
    dis.assign(n + 1, inf);
    vis.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return 0;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return 1;
}

void solve()
{
    int n, m;   std::cin >> n >> m;
    e.resize(n + 1);
    for (int i = 1;i <= m;i++)
    {
        int u, v, w;    std::cin >> u >> v >> w;
        e[u].push_back({ v,-w });
    }
    int f1 = spfa(n, 1);
    std::vector<int> a = dis;
    int f2 = spfa(n, n);
    std::vector<int> b = dis;
    if (!f1 || !f2) {
        std::cout << "Forever love";
        return;
    }
    // int mn = inf;
    // for (int i = 1;i <= n;i++)
    //     mn = std::min(mn, a[i] + b[i]);
    // std::cout << mn;
    std::cout << std::min(a[n], b[1]);
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