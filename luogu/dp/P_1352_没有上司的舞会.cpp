#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e4;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int n;
std::vector<std::vector<int>> adj(N);
int dp[N][2];

void dfs(int c) {
    for (auto x : adj[c])
    {
        dfs(x);
        dp[c][0] += std::max(dp[x][0], dp[x][1]);
        dp[c][1] += dp[x][0];
    }
    return;
}

void solve()
{
    std::cin >> n;
    std::vector<int> ishead(n + 1, 1);
    for (int i = 1;i <= n;i++)
        std::cin >> dp[i][1];

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[v].push_back(u);
        ishead[u] = 0;
    }

    for (int i = 1; i <= n;i++)
    {
        if (ishead[i]) {
            dfs(i);
            std::cout << std::max(dp[i][1], dp[i][0]);
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}