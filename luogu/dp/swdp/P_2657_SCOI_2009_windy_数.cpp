#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 12;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int a[N];
int f[N][10];
void solve()
{
    int l, r;   std::cin >> l >> r;
    auto dfs = [&](auto&& self, int limit, int lead0, int last, int pos) -> i64 {
        if (!pos) return 1;
        if (!limit && !lead0 && ~f[pos][last]) return f[pos][last];

        int up = limit ? a[pos] : 9;
        i64 res = 0;
        for (int i = 0; i <= up;i++) {
            if (lead0) res += self(self, limit && i == up, lead0 && i == 0, i == 0 ? -2 : i, pos - 1);
            else
                if (std::abs(i - last) >= 2)
                    res += self(self, limit && i == up, 0, i, pos - 1);
        }
        if (!limit && !lead0)
            f[pos][last] = res;
        return res;
        };

    auto op = [&](int x) {
        int len = 0;
        while (x) {
            a[++len] = x % 10;
            x /= 10;
        }
        return dfs(dfs, 1, 1, -2, len);
        };

    std::cout << op(r) - op(l - 1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(f, -1, sizeof f);
    solve();
}