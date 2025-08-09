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
const int mod = 998244353;

void solve()
{
    int m, n;   std::cin >> m >> n;
    std::vector<int> a(n + 1), b(n + 1);

    std::set<int> have;
    for (int i = 1;i <= n;i++)   std::cin >> a[i], have.insert(a[i]);
    for (int i = 1;i <= n;i++)   std::cin >> b[i], have.insert(b[i]);

    std::vector<int> to(m + 1);//值对应的编号
    std::vector<int> re(2 * n + 2);//编号对应的值
    int cnt = 1;
    to[m] = cnt;
    re[cnt] = m;

    std::vector adj(2 * n + 2, std::vector<int>());//根据编号的邻接表
    for (int i = 1;i <= n;i++) {
        int mx = std::max(a[i], b[i]);
        adj[cnt + 1].push_back(to[mx]);
        adj[cnt + 2].push_back(to[mx]);
        adj[to[mx]].push_back(cnt + 1);
        adj[to[mx]].push_back(cnt + 2);
        to[a[i]] = cnt + 1;
        to[b[i]] = cnt + 2;
        re[cnt + 1] = a[i];
        re[cnt + 2] = b[i];
        cnt += 2;
    }

    std::vector<int> yezi;
    auto dfs = [&](auto&& self, int u, int fa) -> void {
        if (adj[u].size() == 1) yezi.push_back(re[u]);
        for (auto v : adj[u])
        {
            if (v == fa) continue;
            self(self, v, u);
        }
        };
    dfs(dfs, 1, 1);

    std::vector<int> hav;
    for (auto it : have)
        hav.push_back(it);

    for (int i = 1;i <= n;i++)
        a[i] = std::min(yezi[i - 1], yezi[i]);
    std::sort(a.begin() + 1, a.end());

    i64 ans = 1;
    cnt = 0;
    for (int i = m;i >= 1;i--) {
        if (have.count(i)) continue;

        int x = std::lower_bound(hav.begin(), hav.end(), i) - hav.begin();
        int y = std::lower_bound(a.begin() + 1, a.end(), i) - a.begin() - 1;

        ans *= (2ll * (n + 1 - x) - (n - y) + cnt);
        ans %= mod;
        cnt++;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}