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
    int n, V;   std::cin >> n >> V;
    std::vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> v[i] >> w[i];

    std::vector<int> dp(V + 1, 0);
    for (int i = 1;i <= n;i++)
        for (int j = v[i]; j <= V;j++)
            dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
    std::cout << dp[V];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}