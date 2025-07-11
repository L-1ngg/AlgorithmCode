#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int M = 5e5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    std::vector<int> dp(M + 1, inf);
    dp[1] = 1;

    std::vector<int> divisor[M + 1];
    for (int i = 1;i * 2 <= M;i++) {
        for (int j = i * 2;j <= M;j += i)
            divisor[j].push_back(i);
    }

    // for (int m = 2;m <= M;m++)
    //     for (int i = 1;i * i <= m;i++) {
    //         if (m % i != 0) continue;
    //         if (i > 2) dp[m] = std::min(dp[m], dp[m / i] + dp[i - 2]);
    //         if (m / i > 2) dp[m] = std::min(dp[m], dp[m / i - 2] + dp[i]);
    //     }

    for (int m = 2;m <= M;m++)
        for (auto d : divisor[m]) {
            if (d > 2) dp[m] = std::min(dp[m], dp[m / d] + dp[d - 2]);
            if (m / d > 2) dp[m] = std::min(dp[m], dp[m / d - 2] + dp[d]);
        }
    int t;  std::cin >> t;
    while (t--) {
        int m;  std::cin >> m;
        std::cout << (dp[m] == inf ? -1 : dp[m]);
        std::cout << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}