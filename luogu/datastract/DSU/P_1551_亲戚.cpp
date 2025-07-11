#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

void solve()
{
    int n, m, p;
    std::cin >> n >> m >> p;
    dsu DSU(n);

    for (int i = 1; i <= m; i++)
    {
        int x1, x2;
        std::cin >> x1 >> x2;
        DSU.merge(--x1, --x2);
    }

    for (int i = 1; i <= p;i++)
    {
        int x1, x2;
        std::cin >> x1 >> x2;
        if (DSU.get_root(--x1) == DSU.get_root(--x2))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}