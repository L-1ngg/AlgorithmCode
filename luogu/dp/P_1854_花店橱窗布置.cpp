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
    int n, v;   std::cin >> n >> v;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(v + 1));
    std::vector<std::vector<int>> pre(n + 1, std::vector<int>(v + 1));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= v;j++)
            std::cin >> a[i][j];
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(v + 1, -inf));
    dp[1][1] = a[1][1];
    for (int i = 1;i <= v;i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1;j <= v;j++) {
            for (int k = j - 1; k >= 1;k--)
                if (dp[i - 1][k] + a[i][j] >= dp[i][j])
                {
                    dp[i][j] = dp[i - 1][k] + a[i][j];
                    pre[i][j] = k;
                }
        }
    std::deque<int> ans;
    int p = max_element(dp[n].begin(), dp[n].end()) - dp[n].begin();
    std::cout << dp[n][p] << '\n';
    int i = n;
    while (i >= 1) {
        ans.push_front(p);
        p = pre[i][p];
        i--;
    }
    for (auto x : ans)
        std::cout << x << ' ';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}