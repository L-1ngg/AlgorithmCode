// https://www.acwing.com/problem/content/description/10/

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

std::vector<std::vector<int>> g(105);
int dp[105][105];
int n, V;
int v[105], w[105];

void dfs(int c) {
    for (int i = v[c]; i <= V;i++)
        dp[c][i] = w[c];

    for (auto s : g[c]) {
        dfs(s);
        for (int i = V;i >= v[c];i--)
            for (int j = 0; j <= i - v[c];j++)
                dp[c][i] = std::max(dp[c][i], dp[c][i - j] + dp[s][j]);
    }
}

void solve()
{
    std::cin >> n >> V;
    int st;
    for (int i = 1; i <= n;i++)
    {
        int fa;
        std::cin >> v[i] >> w[i] >> fa;
        if (fa == -1) st = i;
        else g[fa].push_back(i);
    }

    dfs(st);
    std::cout << dp[st][V];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}