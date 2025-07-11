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
const i64 inf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, X;    std::cin >> n >> m >> X;
    std::vector adj1(n + 1, std::vector<int>());
    std::vector<std::vector<int>> adj2(n + 1);

    for (int i = 1; i <= m;i++)
    {
        int u, v;   std::cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    std::vector d(n + 1, std::vector<i64>(2, inf));

    struct node {
        i64 dis, pos, f;

        bool operator>(const node& n)
        {
            return dis > n.dis;
        }
    };

    std::priority_queue<node, std::vector<node>, std::greater<>> pq;
    pq.push({ 0,1,0 });

    while (!pq.empty())
    {
        auto [dis, pos, f] = pq.top();
        pq.pop();
        if (d[pos][f] <= dis)  continue;
        d[pos][f] = dis;

        if (!f)
        {
            for (auto u : adj1[pos])
                pq.push({ dis + 1, u, 0 });
            for (auto u : adj2[pos])
                pq.push({ dis + X + 1, u, 1 });
        }
        else
        {
            for (auto u : adj1[pos])
                pq.push({ dis + X + 1, u, 0 });
            for (auto u : adj2[pos])
                pq.push({ dis + 1, u, 1 });
        }
    }

    std::cout << std::min(d[n][0], d[n][1]);
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