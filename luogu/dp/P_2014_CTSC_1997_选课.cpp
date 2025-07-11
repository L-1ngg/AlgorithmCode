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

int n, m;
int dp[303][303]; // dp[i][j] 表示以i为根的子树中,节点个数为j个的最大价值
int s[303] = { 0 };
std::vector<std::vector<int>> g(303);
void dfs(int c) {
    dp[c][1] = s[c];

    for (auto s : g[c]) {
        dfs(s);
        for (int i = m + 1;i >= 1;i--)
            for (int j = 0; j <= i - 1;j++)
                dp[c][i] = std::max(dp[c][i], dp[c][i - j] + dp[s][j]);
    }
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n;i++) {
        int k;  std::cin >> k >> s[i];
        g[k].push_back(i);
    }
    dfs(0);
    std::cout << dp[0][m + 1];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}