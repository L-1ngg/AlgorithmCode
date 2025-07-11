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
    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1;i <= m;i++)
    {
        int u, v;   std::cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    std::vector<int> nex(n + 1);
    std::iota(nex.begin(), nex.end(), 0);
    int ans = n + m;
    do {
        bool f = 1;
        for (int i = 1;i <= n;i++) {
            if (nex[i] == i || nex[nex[i]] == i)
            {
                f = 0;
                break;
            }
        }
        if (!f) continue;
        int cnt = 0;
        for (int i = 1;i <= n;i++) {
            if (g[i][nex[i]])
                cnt++;
        }
        ans = std::min(ans, m - cnt + n - cnt);
    } while (next_permutation(nex.begin() + 1, nex.end()));
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