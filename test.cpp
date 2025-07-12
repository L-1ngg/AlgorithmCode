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

std::vector<int> color;

struct HLD {
    vector<vector<int>> e;
    vector<int> siz, son;
    vector<i64> ans;
    set<int> cnt;
    i64 sum, Max;
    int hson;
    HLD(int n) {
        e.resize(n + 1);
        siz.resize(n + 1);
        son.resize(n + 1);
        ans.resize(n + 1);
        // cnt.resize(n + 1);
        hson = 0;
        sum = 0;
        Max = 0;
    }
    void add(int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }
    void dfs1(int u, int fa) {
        siz[u] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
    }
    void calc(int u, int fa) {
        cnt.insert(color[u]);
        // if (cnt[color[u]] > Max) {
        //     Max = cnt[color[u]];
        //     sum = color[u];
        // }
        // else if (cnt[color[u]] == Max) {
        //     sum += color[u];
        // }
        for (auto v : e[u]) {
            if (v == fa || v == hson) continue;
            calc(v, u);
        }
    }
    void dfs2(int u, int fa, int opt) {
        for (auto v : e[u]) {
            if (v == fa || v == son[u]) continue;
            dfs2(v, u, 0);
        }
        if (son[u]) {
            dfs2(son[u], u, 1);
            hson = son[u]; //记录重链编号，计算的时候跳过
        }
        calc(u, fa);
        hson = 0; //消除的时候所有儿子都清除
        ans[u] = cnt.size();
        if (!opt) {
            cnt.clear();
            sum = 0;
            Max = 0;
        }
    }
};

void solve()
{
    int n;  std::cin >> n;
    color.assign(n + 1, 0);
    HLD hld(n);
    for (int i = 1;i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        hld.add(u, v);
    }
    for (int i = 1;i <= n;i++)  std::cin >> color[i];
    hld.dfs1(1, 0);
    hld.dfs2(1, 0, 0);
    int q;  std::cin >> q;
    while (q--) {
        int x;  std::cin >> x;
        std::cout << hld.ans[x] << '\n';
    }
    // for (int i = 1;i <= n;i++)
    //     std::cout << hld.ans[i] << " \n"[i == n];
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