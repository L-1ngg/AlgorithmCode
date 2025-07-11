#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 15;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;


int a[N];
int f[N][N];
void solve()
{
    i64 l, r;   std::cin >> l >> r;

    int digit;
    auto dfs = [&](auto&& self, bool limit, bool lead0, int pos, int cnt) {
        if (!pos) return cnt;
        if (digit == 0 && !limit && ~f[pos][cnt] && !lead0) return f[pos][cnt];
        if (digit != 0 && !limit && ~f[pos][cnt]) return f[pos][cnt];

        int up = limit ? a[pos] : 9;
        int tmp = 0;
        for (int i = 0;i <= up;i++) {
            int c = cnt + (i == digit);
            if (lead0 && digit == 0 && i == 0)
                c = 0;
            tmp += self(self, limit && i == up, lead0 && i == 0, pos - 1, c);
        }
        if (!limit && !lead0)
            f[pos][cnt] = tmp;
        return tmp;
        };

    int num[10]{};
    auto op = [&](i64 x, int f) {
        int len = 0;
        while (x) {
            a[++len] = x % 10;
            x /= 10;
        }
        for (digit = 0; digit <= 9;digit++) {
            num[digit] += dfs(dfs, 1, 1, len, 0) * f;
        }
        };

    op(r, 1), op(l - 1, -1);
    for (int i = 0; i <= 9;i++) {
        std::cout << num[i] << " \n"[i == 9];
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(f, -1, sizeof f);
    solve();
}