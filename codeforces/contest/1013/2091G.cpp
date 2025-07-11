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

void solve()
{
    int n, k;   std::cin >> n >> k;
    if (n % k == 0)
    {
        std::cout << k << '\n';
        return;
    }
    if (n > k * k)
    {
        std::cout << std::max(1, k - 2) << '\n';
        return;
    }

    std::vector<int> vis(n + 1, 0);
    vis[0] = 1;
    int d = 1;
    auto bfs = [&]()
        {
            std::queue<int> q;
            for (int i = 0; i <= n;i++)
            {
                if (vis[i])
                    q.push(i);
            }
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (u + d * k >= 0 && u + d * k <= n && !vis[u + d * k]) {
                    vis[u + d * k] = 1;
                    q.push(u + d * k);
                }
            }
        };

    while (true)
    {
        bfs();
        if (vis[n])
        {
            std::cout << k << '\n';
            return;
        }

        d = -d;
        k = std::max(1, k - 1);
        std::vector<int> tmp(n + 1);
        for (int i = 0; i <= n;i++)
        {
            if (vis[i])
            {
                if (i + d * k >= 0 && i + d * k <= n)
                    tmp[i + d * k] = 1;
            }
        }
        vis = tmp;
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