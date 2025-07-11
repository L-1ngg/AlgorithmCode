#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e3 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

i64 mp[1005][105];
i64 dp[1005][105];
int path[1005][105];
void solve()
{
    int W, H;   std::cin >> W >> H;
    H--;
    int t, x, v, score;
    int maxt = 0;

    while (std::cin >> t >> x >> v >> score)
    {
        if (H % v != 0)
            continue;
        int T = H / v + t;
        maxt = std::max(maxt, T);
        mp[T][x] += score;
    }

    for (int i = maxt; i >= 0; i--)
        for (int j = 1; j <= W; j++)
            for (int k = -2; k <= 2; k++)
            {
                if (j + k >= 1 && j + k <= W)
                    if (dp[i][j] < dp[i + 1][j + k] + mp[i][j])
                    {
                        dp[i][j] = dp[i + 1][j + k] + mp[i][j];
                        path[i][j] = k;
                    }
            }

    std::cout << dp[0][(W >> 1) + 1] << '\n';

    int k = path[0][(W >> 1) + 1];
    int s = (W >> 1) + 1;
    for (int i = 0; i < maxt; i++)
    {
        std::cout << path[i][s] << '\n';
        s += path[i][s];
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}