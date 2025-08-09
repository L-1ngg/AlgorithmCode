#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::string a[3];  std::cin >> a[1] >> a[2];
    a[1] = " " + a[1];
    a[2] = " " + a[2];
    std::vector vis(3, std::vector<a3>(n + 1, { 0,0 }));
    std::queue<a3> q;
    q.push({ 1,1,0 });
    vis[1][1][0] = 1;
    while (q.size()) {
        auto [x, y, st] = q.front();
        q.pop();

        if (st == 0) {
            for (int i = 0;i < 4;i++)
            {
                int nowx = x + dx[i], nowy = y + dy[i];
                if (nowx >= 1 && nowx <= 2 && nowy >= 1 && nowy <= n && vis[nowx][nowy][1] == 0)
                    q.push({ nowx, nowy, 1 }), vis[nowx][nowy][1] = 1;
            }
        }
        else {
            int nowx = x;
            int nowy = y + (a[x][y] == '<' ? -1 : 1);
            if (vis[nowx][nowy][0] == 0)
                q.push({ nowx, nowy, 0 }), vis[nowx][nowy][0] = 1;
        }
    }
    if (vis[2][n][0] || vis[2][n][1])   std::cout << "YES";
    else std::cout << "NO";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}