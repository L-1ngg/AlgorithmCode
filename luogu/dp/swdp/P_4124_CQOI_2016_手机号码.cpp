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

int a[N + 1];
i64 f[N + 1][N][N][2][2][2];
void solve()
{
    i64 l, r;   std::cin >> l >> r;
    int len;

    auto dfs = [&](auto&& self, bool limit, int pos, int last2, int last1, bool same, bool have4, bool have8) ->i64 {
        if (!pos) {
            if (same)return 1;
            else return 0;
        }
        auto& now = f[pos][last2][last1][same][have4][have8];
        if (!limit && ~now) return  now;

        int up = limit ? a[pos] : 9;
        i64 res = 0;
        for (int i = 0;i <= up;i++) {
            if (pos == len && i == 0) continue;
            if (have4 && i == 8) continue;
            if (have8 && i == 4) continue;
            res += self(self, limit && i == up, pos - 1, last1, i, same || ((last2 == last1) && (last1 == i)), have4 || (i == 4), have8 || (i == 8));
        }
        if (!limit) now = res;
        return res;
        };

    auto op = [&](i64 x) {
        if (x < 1e10) return 0ll;
        len = 0;
        while (x) {
            a[++len] = x % 10;
            x /= 10;
        }
        return dfs(dfs, 1, len, -1, -1, 0, 0, 0);
        };

    memset(f, -1, sizeof f);
    std::cout << op(r) - op(l - 1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}