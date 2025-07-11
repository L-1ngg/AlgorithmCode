#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second

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

int cost[105];
pii st[105];
pii to[105];

void solve()
{
    int n, m;   std::cin >> n >> m;
    int max = (1 << n) - 1;
    for (int i = 1; i <= m;i++)
    {
        std::cin >> cost[i];
        std::string s1, s2; std::cin >> s1 >> s2;

        int n1 = 0, n2 = 0;
        for (auto x : s1)
        {
            if (x == '+')
                n1 |= 1;
            else if (x == '-')
                n2 |= 1;
            n1 <<= 1, n2 <<= 1;
        }
        n1 >>= 1, n2 >>= 1;
        st[i].x = n1, st[i].y = n2;

        n1 = 0, n2 = 0;
        for (auto x : s2)
        {
            if (x == '-')
                n1 |= 1;
            else if (x == '+')
                n2 |= 1;
            n1 <<= 1, n2 <<= 1;
        }
        n1 >>= 1, n2 >>= 1;
        // std::cout << n1 << ' ' << n2 << '\n';
        to[i].x = ~n1, to[i].y = n2;
    }

    std::queue<pii> q;
    q.push({ (1 << n) - 1,0 });
    std::vector<int> vis((1 << n) - 1, inf);
    vis[(1 << n) - 1] = 0;

    int ans = inf;
    while (!q.empty())
    {
        auto [status, step] = q.front();
        q.pop();

        if (status == 0)
        {
            ans = std::min(step, ans);
            continue;
        }

        for (int i = 1; i <= m;i++)
        {
            int tmp = status;
            if ((tmp | st[i].x) > tmp)  continue;
            if ((tmp & st[i].y))    continue;
            tmp &= to[i].x;
            tmp |= to[i].y;
            if (vis[tmp] > step + cost[i])
            {
                q.push({ tmp,step + cost[i] });
                vis[tmp] = step + cost[i];
            }
        }
    }

    if (ans == inf)
        std::cout << "0";
    else std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}