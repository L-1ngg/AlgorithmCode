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
    int n, m, k;    std::cin >> n >> m >> k;
    std::vector g(n + 1, std::vector<int>(m + 1));
    std::vector d(g);
    std::queue<a3> q;

    for (int i = 1;i <= k;i++) {
        int x, y;   std::cin >> x >> y;
        d[x][y] = 2;
        q.push({ x,y,0 });
    }

    while (!q.empty()) {
        //cnt 最短路
        auto [x, y, cnt] = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            if (x + dx[i] <= 0 || x + dx[i] >= n + 1 || y + dy[i] <= 0 || y + dy[i] >= m + 1)
                continue;
            if (d[x + dx[i]][y + dy[i]] == 2) continue;
            d[x + dx[i]][y + dy[i]]++;
            if (d[x + dx[i]][y + dy[i]] == 2) {
                g[x + dx[i]][y + dy[i]] = cnt + 1;
                q.push({ x + dx[i] ,y + dy[i] , cnt + 1 });
            }
        }
    }
    i64 ans = 0;
    for (int i = 1;i <= n;i++)
        ans += std::accumulate(g[i].begin(), g[i].end(), 0);
    std::cout << ans;
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