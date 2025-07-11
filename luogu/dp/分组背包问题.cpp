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
    std::vector<int> dp(V + 1);

    for (int t = 1; t <= n;t++) {
        int s;  std::cin >> s;
        std::vector<int> v(s + 1), w(s + 1);
        for (int i = 1;i <= s;i++)
            std::cin >> v[i] >> w[i];

        for (int i = V; i >= 0;i--)
            for (int j = 1; j <= s;j++)
                if (v[j] <= i) {
                    dp[i] = std::max(dp[i], dp[i - v[j]] + w[j]);
                }
    }
    std::cout << dp[V];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}