#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, h;    std::cin >> n >> m >> h;
    std::vector<std::vector<char>> g(n + 1, std::vector<char>(m + 1));
    pii st, en;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m; j++)
        {
            std::cin >> g[i][j];
            if (g[i][j] == '*')
                st.x = i, st.y = j;
            if (g[i][j] == '%')
                en.x = i, en.y = j;
        }

    a2 ini;
    ini[0] = inf, ini[1] = inf;
    //d[i][j][k] 表示走到i,j位置,并且状态为k的时候的最短路
    std::vector<std::vector<a2>> d(n + 1, std::vector<a2>(m + 1, ini));

    struct node {
        int x, y, dis, f;

        //此时使用的是std::greater<>,若返回为true,表示大的dis优先级更低
        bool operator>(const node& n) const {
            return dis > n.dis;
        }
        //此时使用的是std::less<>,若返回为true,表示大的dis优先级更低
        // bool operator<(const node& n) const {
        //     return dis > n.dis;
        // }
    };
    std::priority_queue<node, std::vector<node>, std::greater<node>> pq;
    // std::priority_queue<node> pq;
    pq.push({ st.x,st.y,0,1 });
    while (!pq.empty())
    {
        auto [x, y, dis, f] = pq.top();
        pq.pop();
        if (d[x][y][f] <= dis)  continue;
        d[x][y][f] = dis;

        if (x == n)  continue;
        if (f)
        {
            if (g[x + 1][y] == '#')
            {
                pq.push({ x + 1,y,dis + h + 1,1 });
                if (y - 1 >= 1 && g[x][y - 1] != '#')
                    pq.push({ x,y - 1,dis + 1,0 });
                if (y + 1 <= n && g[x][y + 1] != '#')
                    pq.push({ x,y + 1,dis + 1,0 });
            }
            else
                pq.push({ x + 1,y,dis + 1,1 });
        }
        else
        {
            if (g[x + 1][y] == '#')
            {
                if (y - 1 >= 1 && g[x][y - 1] != '#')
                    pq.push({ x,y - 1,dis + 1,0 });
                if (y + 1 <= n && g[x][y + 1] != '#')
                    pq.push({ x,y + 1,dis + 1,0 });
            }
            else
                pq.push({ x + 1,y,dis + 1,1 });
        }
    }
    if (std::min(d[en.x][en.y][1], d[en.x][en.y][0]) == inf)
        std::cout << "-1\n";
    else
        std::cout << std::min(d[en.x][en.y][1], d[en.x][en.y][0]);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}