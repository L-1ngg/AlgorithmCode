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
const int MAXN = (1 << 10) - 1;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int a[105][15];
int vis[MAXN + 1];

void solve()
{
    int n, m;   std::cin >> n >> m;
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n;j++)
            std::cin >> a[i][j];

    std::queue<pii> q; // step & status
    q.push({ 0, (1 << n) - 1 });
    vis[(1 << n) - 1] = 1;

    int ans = -1;
    while (!q.empty())
    {
        auto [step, st] = q.front();
        q.pop();
        if (st == 0)
        {
            ans = step;
            break;
        }

        for (int i = 1; i <= m;i++)
        {
            int tmp = st;
            for (int j = 1; j <= n;j++)
            {
                if (a[i][j] == 1 && (tmp & (1 << j - 1)))  tmp ^= (1 << j - 1);
                if (a[i][j] == -1 && !(tmp & (1 << j - 1))) tmp |= (1 << j - 1);
            }
            if (!vis[tmp])
            {
                q.push({ step + 1,tmp });
                vis[tmp] = 1;
            }
        }
    }

    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}