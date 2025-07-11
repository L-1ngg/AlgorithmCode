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
    std::queue<pii> q;
    std::map<pii, int> vis, mp;
    for (int i = 1;i <= k;i++) {
        int x, y;   std::cin >> x >> y;
        if (x == 1 || y == m) q.push({ x,y });
        mp[{x, y}] = 1;
    }

    int f = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n || y == 1) f = 1;
        if (vis[{x, y}]) continue;
        vis[{x, y}] = 1;

        for (int i = 0;i < 8;i++) {
            if (x + dx[i] >= n + 1 || y + dy[i] <= 0 || y + dy[i] >= m + 1) continue;
            if (mp[{x + dx[i], y + dy[i]}]) q.push({ x + dx[i], y + dy[i] });
        }
    }
    std::cout << (f ? "No" : "Yes");
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