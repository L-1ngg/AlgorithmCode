#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 998244353;

struct DSU {
    std::vector<int> d;
    DSU(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int find(int x) { return d[x] = (x == d[x] ? x : find(d[x])); };
    bool merge(int u, int v) {
        if (find(u) != find(v)) {
            d[find(u)] = find(v);
            return true;
        }
        else return false;
    }
};

void solve()
{
    int n, m1, m2;  std::cin >> n >> m1 >> m2;

    DSU dsu1(n), dsu2(n);
    std::vector<pii> a(m1);
    for (auto& [u, v] : a) {
        std::cin >> u >> v;
        u--, v--;
    }
    for (int i = 1; i <= m2;i++)
    {
        int u, v;   std::cin >> u >> v;
        u--, v--;
        dsu2.merge(u, v);
    }

    int ans = 0;
    for (auto [u, v] : a)
    {
        if (dsu2.find(u) != dsu2.find(v))
            ans++;
        else dsu1.merge(u, v);
    }

    int sz1 = 0, sz2 = 0;
    for (int i = 0;i < n;i++)
    {
        sz1 += dsu1.find(i) == i;
        sz2 += dsu2.find(i) == i;
    }
    std::cout << ans + sz1 - sz2 << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}