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
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<a4> adj(n + 1);
    for (int i = 1;i <= n;i++) {
        std::cin >> adj[i][0];
        for (int j = 1;j <= adj[i][0];j++)
            std::cin >> adj[i][j];
    }

    std::vector<a4> f(n + 1), vis(n + 1);
    for (int i = 1;i <= n;i++) {
        if (f[i][1] == 0) {
            int sum = 0;
            auto dfs = [&](auto&& self, int x, int now)->void {
                if (vis[x][now]) return;
                vis[x][now] = 1;
                int y = adj[x][now], nex;
                for (int i = 1;i <= adj[y][0];i++) {
                    if (x == adj[y][i]) {
                        if (vis[y][i] == 0) sum++;
                        nex = (i) % adj[y][0] + 1;
                    }
                }
                self(self, y, nex);
                f[x][now] = sum;
                vis[x][now] = 0;
                };
            dfs(dfs, i, 1);
        }
        std::cout << f[i][1] << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}