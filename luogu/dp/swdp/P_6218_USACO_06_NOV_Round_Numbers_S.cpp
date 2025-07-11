#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 35;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int a[N];
int f[N][N][N];
void solve()
{
    //由于要统计0的个数,因此,我们需要一个lead0参数
    int l, r;   std::cin >> l >> r;
    auto dfs = [&](auto&& self, bool limit, bool lead0, int pos, int cnt0, int cnt1) {
        if (!pos) {
            if (cnt0 >= cnt1) return 1;
            else return 0;
        }
        if (!limit && !lead0 && ~f[pos][cnt0][cnt1]) return f[pos][cnt0][cnt1];

        int up = limit ? a[pos] : 1;
        int res = 0;
        for (int i = 0;i <= up;i++) {
            res += self(self, limit && i == up, lead0 && i == 0, pos - 1, (lead0 && i == 0 ? 0 : cnt0 + (i == 0)), cnt1 + (i == 1));
        }
        if (!limit && !lead0) f[pos][cnt0][cnt1] = res;
        return res;
        };

    auto op = [&](int x) {
        int len = 0;
        while (x) {
            a[++len] = x % 2;
            x /= 2;
        }
        return dfs(dfs, 1, 1, len, 0, 0);
        };
    std::cout << op(r) - op(l - 1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    memset(f, -1, sizeof f);
    solve();
}