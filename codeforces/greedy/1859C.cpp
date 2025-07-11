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
    int n;  std::cin >> n;
    i64 ans = 0;
    for (int mx = n * n;;mx--)
    {
        DSU dsu(n + 1);
        i64 res = 0;
        bool ok = 1;
        for (int i = n; i >= 1; i--)
        {
            int x = dsu.find(std::min(n, mx / i));
            if (x == 0)
            {
                ok = false;break;
            }
            res += x * i;
            dsu.merge(x, x - 1);
        }
        if (!ok)
            break;
        ans = std::max(ans, res - mx);
    }
    std::cout << ans << '\n';
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