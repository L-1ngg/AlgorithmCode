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


struct Tree {
    int n;
    vector<vector<int>> ver;
    vector<int> f;
    Tree(int n) {
        this->n = n;
        ver.resize(n + 1);
        f.resize(n + 1);
    }
    void add(int x, int y) {
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    int getlen(int root) { // 获取x所在树的直径
        map<int, int> dep; // map用于优化输入为森林时的深度计算，亦可用vector
        auto dfs = [&](auto&& self, int x, int fa) -> void {
            f[x] = fa;
            for (auto y : ver[x]) {
                if (y == fa) continue;
                dep[y] = dep[x] + 1;
                self(self, y, x);
            }
            if (dep[x] > dep[root]) {
                root = x;
            }
            };
        dfs(dfs, root, 0);
        int st = root; // 记录直径端点

        dep.clear();
        dfs(dfs, root, 0);
        int ed = root; // 记录直径另一端点

        return ed;
    }
};

void solve()
{
    int n;  std::cin >> n;
    Tree tr(n);
    for (int i = 1;i <= n;i++)
    {
        int u, v;   std::cin >> u >> v;
        tr.add(u, v);
    }

    std::vector<int> a;
    std::vector<int> v(n + 1);
    for (int i = tr.getlen(1);i;i = tr.f[i])
    {
        v[i] = 1;
        a.push_back(i);
    }

    auto dfs1 = [&](auto&& self, int x, int fa)->int {
        int d1 = 0, d2 = 0;
        for (auto y : tr.ver[x]) {
            if (y == fa || v[y]) continue;
            int len = self(self, y, x) + 1;
            if (len > d1) d2 = d1, d1 = len;
            else if (len > d2) d2 = len;
        }
        return d1;
        };
    std::vector<int> mx_dis(n + 1);
    for (auto x : a) {
        mx_dis[x] = dfs1(dfs1, x, 0) + 1;
    }
    std::vector<int> v1(n + 1);

    int mx = 0;
    for (int i = 1;i <= n;i++) {
        auto dfs2 = [&](auto&& self, int x, int fa)->int {
            int d1 = 0, d2 = 0;
            v1[x] = 1;
            for (auto y : tr.ver[x]) {
                if (y == fa || v[y]) continue;
                int len = self(self, y, x) + 1;
                if (len > d1) d2 = d1, d1 = len;
                else if (len > d2) d2 = len;
            }
            mx = std::max(mx, d1 + d2);
            return d1;
            };
        if (v[i] || v1[i]) continue;
        dfs2(dfs2, i, 0);
    }
    mx++;
    std::map<int, int> ans;
    ans[a.size()] = mx;
    ans[mx] = a.size();

    std::vector<int> suf(n + 1);
    suf[a.size()] = 0;
    for (int i = a.size() - 2; i >= 0; i--) {
        suf[i + 1] = max(suf[i + 2], (int)a.size() - i - 2 + mx_dis[a[i + 1]]);
    }
    for (int i = 0; i < a.size() - 1; i++) {
        int x = i + mx_dis[a[i]];
        int y = suf[i + 1];
        ans[x] = max(ans[x], y);
        ans[y] = max(ans[y], x);
    }
    i64 res = 0;
    mx = 0;
    for (int i = a.size(); i >= 1; i--) {
        mx = max(mx, ans[i]);
        res += mx;
    }
    std::cout << res << '\n';
}

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}