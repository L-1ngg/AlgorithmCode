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

void solve()
{
    int n, V, M;    std::cin >> n >> V >> M;
    std::vector<int> v(n + 1), m(n + 1), w(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> v[i] >> m[i] >> w[i];

    int dp[103][103]{};
    for (int t = 1; t <= n;t++)
        for (int i = V;i >= v[t];i--)
            for (int j = M; j >= m[t];j--) {
                dp[i][j] = std::max(dp[i][j], dp[i - v[t]][j - m[t]] + w[t]);
            }
    std::cout << dp[V][M];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}