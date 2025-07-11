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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    int l, r;   std::cin >> l >> r;
    std::vector<std::string> a(n + 1);
    std::vector ans(n + 1, std::vector<a2>(m + 1, { inf,inf }));
    for (int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        a[i] = " " + a[i];
    }
    std::priority_queue<a4, std::vector<a4>, std::greater<a4>> pq;
    std::vector vis(n + 1, std::vector<a2>(m + 1, { 0,0 }));
    pq.push({ 0,1,1,0 });

    while (!pq.empty()) {
        auto [d, x, y, f] = pq.top();
        pq.pop();
        if (vis[x][y][f]) continue;
        vis[x][y][f] = 1;
        auto yes = [&](int i) {
            if (x + dx[i] < 1 || x + dx[i] > n) return 0;
            if (y + dy[i] < 1 || y + dy[i] > m) return 0;
            if (a[x + dx[i]][y + dy[i]] == '0') return 0;
            return 1;
            };
        for (int i = 0;i < 8;i++) {
            if (yes(i) && ans[x + dx[i]][y + dy[i]][f ^ 1] > d + 1)
            {
                ans[x + dx[i]][y + dy[i]][f ^ 1] = d + 1;
                pq.push({ d + 1,x + dx[i],y + dy[i],f ^ 1 });
            }
        }
    }
    if (ans[n][m][0] == inf && ans[n][m][1] == inf) {
        std::cout << "-1\n";
        return;
    }
    if (l != r)
        std::cout << (std::min(ans[n][m][0], ans[n][m][1]) + r - 1) / r << '\n';
    else if (l & 1) {
        int ans1 = (ans[n][m][1] + l - 1) / l;
        int ans0 = (ans[n][m][0] + l - 1) / l;
        if (!(ans1 & 1)) ans1++;
        if (ans0 & 1) ans0++;
        if (ans[n][m][1] == inf) std::cout << ans0 << '\n';
        else if (ans[n][m][0] == inf) std::cout << ans1 << '\n';
        else std::cout << std::min(ans1, ans0) << '\n';
    }
    else {
        if (ans[n][m][0] == inf) std::cout << "-1\n";
        else std::cout << (ans[n][m][0] + l - 1) / l << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}