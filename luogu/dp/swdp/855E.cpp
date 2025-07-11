#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 10;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int a[67];
i64 f[N + 1][67][(1 << N)];

void solve()
{
    int d;
    i64 l, r;
    std::cin >> d >> l >> r;

    auto dfs = [&](auto&& self, bool limit, bool lead0, int pos, i64 st) ->i64 {
        if (!pos) return (st == 0 ? 1ll : 0ll);
        auto& now = f[d][pos][st];
        if (!limit && !lead0 && ~now) return now;

        i64 res = 0;
        int up = limit ? a[pos] : d - 1;
        for (int i = 0; i <= up;i++) {
            i64 tmp = (lead0 && i == 0 ? 0 : st ^ (1 << i));
            res += self(self, limit && i == up, lead0 && i == 0, pos - 1, tmp);
        }
        if (!limit && !lead0) now = res;
        return res;
        };

    auto op = [&](i64 x) {
        int len = 0;
        while (x) {
            a[++len] = x % d;
            x /= d;
        }
        return dfs(dfs, 1, 1, len, 0);
        };

    std::cout << op(r) - op(l - 1) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(f, -1, sizeof f);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}