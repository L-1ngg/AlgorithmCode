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

int g[1003][1003];
int dp[1003][1003];
void solve()
{
    int n, V;   std::cin >> n >> V;
    std::vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> v[i] >> w[i];

    for (int i = n; i >= 1;i--)
        for (int j = 0; j <= V;j++)
        {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i])dp[i][j] = std::max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    for (int i = 1, j = V; i <= n;i++) {
        if (j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i])
        {
            std::cout << i << ' ';
            j -= v[i];
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}