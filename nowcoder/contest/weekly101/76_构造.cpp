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

int lowbit(int x) {
    return x & -x;
}
void solve()
{
    int n, m;   std::cin >> n >> m;
    if (!(m & 1)) {
        std::cout << -1;
        return;
    }
    m--;
    if (!m) {
        for (int i = 1;i <= n;i++)   std::cout << i << " \n"[i == n];
        std::cout << 1 << '\n' << 1 << " " << n;
        return;
    }
    if (m <= n) {
        std::cout << m << " ";
        for (int i = 1;i <= n;i++)
            if (i != m)  std::cout << i << " ";
        std::cout << "\n";
        std::cout << 2 << '\n' << 1 << " " << 1 << "\n" << 2 << " " << n;
    }
    else {
        std::vector<int> ans;
        std::vector<int> vis(n + 1);
        while (m) {
            int x = lowbit(m);
            if (x > n) {
                std::cout << -1;
                return;
            }
            ans.push_back(x);
            vis[x] = 1;
            m -= lowbit(m);
        }
        int cnt = ans.size();
        for (int i = 1;i <= n;i++) if (!vis[i]) ans.push_back(i);

        for (auto x : ans) std::cout << x << " ";
        std::cout << "\n";
        std::cout << cnt + 1 << '\n';
        for (int i = 1;i <= cnt;i++)    std::cout << i << " " << i << '\n';
        std::cout << cnt + 1 << " " << n;
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