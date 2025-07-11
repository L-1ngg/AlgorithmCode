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
const int MAXN = 30 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;


int x[MAXN], y[MAXN], z[MAXN];
int dp[MAXN][3];
int n;

int dfs(int c, int r)
{
    if (dp[c][r] != -1)
        return dp[c][r];
    dp[c][r] = 0;
    int base1, base2;
    if (r == 0)
        base1 = y[c], base2 = z[c];
    else if (r == 1)
        base1 = x[c], base2 = z[c];
    else
        base1 = x[c], base2 = y[c];

    for (int i = 0; i < n; i++)
    {
        if ((x[i] < base1 && y[i] < base2) || (x[i] < base2 && y[i] < base1))
            dp[c][r] = std::max(dp[c][r], dfs(i, 2) + z[i]);
        if ((x[i] < base1 && z[i] < base2) || (x[i] < base2 && z[i] < base1))
            dp[c][r] = std::max(dp[c][r], dfs(i, 1) + y[i]);
        if ((y[i] < base1 && z[i] < base2) || (y[i] < base2 && z[i] < base1))
            dp[c][r] = std::max(dp[c][r], dfs(i, 0) + x[i]);
    }
    return dp[c][r];
}

int dfsall()
{
    for (int i = 0;i < n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }

    int r = 0;
    for (int i = 0; i < n;i++)
    {
        r = std::max(r, dfs(i, 0) + x[i]);
        r = std::max(r, dfs(i, 1) + y[i]);
        r = std::max(r, dfs(i, 2) + z[i]);
    }
    return r;
}

void solve()
{
    int t = 0;
    while (true) {
        std::cin >> n;
        if (n == 0) break;
        t++;
        for (int i = 0; i < n; i++) {
            std::cin >> x[i] >> y[i] >> z[i];
        }
        std::cout << "Case " << t << ":"
            << " maximum height = " << dfsall();
        std::cout << '\n';
    }
    return;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}