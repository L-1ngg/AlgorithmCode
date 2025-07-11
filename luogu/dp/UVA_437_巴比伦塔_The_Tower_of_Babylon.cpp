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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int n, cnt = 0;
int dp[33][3];
int x[33], y[33], z[33];

int check(int x, int y, int xc, int yc) {
    if ((xc < x && yc < y) || (xc < y && yc < x))
        return 1;
    return 0;
}

int sub(int c, int f) {
    if (dp[c][f]) {
        return dp[c][f];
    }

    int b1, b2;
    if (f == 0) {
        b1 = y[c];
        b2 = z[c];
    }
    if (f == 1) {
        b1 = x[c];
        b2 = z[c];
    }
    if (f == 2) {
        b1 = y[c];
        b2 = x[c];
    }

    for (int i = 1;i <= n;i++)
    {
        if (check(b1, b2, y[i], z[i]))
            dp[c][f] = std::max(dp[c][f], sub(i, 0) + x[i]);
        if (check(b1, b2, x[i], z[i]))
            dp[c][f] = std::max(dp[c][f], sub(i, 1) + y[i]);
        if (check(b1, b2, y[i], x[i]))
            dp[c][f] = std::max(dp[c][f], sub(i, 2) + z[i]);
    }
    return dp[c][f];
}

void solve()
{
    cnt++;
    memset(dp, 0, sizeof dp);
    for (int i = 1;i <= n;i++)
        std::cin >> x[i] >> y[i] >> z[i];

    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        ans = std::max(ans, sub(i, 0) + x[i]);
        ans = std::max(ans, sub(i, 1) + y[i]);
        ans = std::max(ans, sub(i, 2) + z[i]);
    }
    std::cout << "Case " << cnt << ": maximum height = ";
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while (1)
    {
        std::cin >> n;
        if (!n) break;
        solve();
    }
}