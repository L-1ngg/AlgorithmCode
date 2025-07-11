#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e5 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

int n;
int nex[N << 1], to[N << 1], head[N << 1], wei[N << 1];
int nxt[N << 5][2], cnt = 0, dis[N], ans;

void add(int u, int v, int w)
{
    nex[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    wei[cnt] = w;
}

void insert(int x)
{
    for (int i = 30, p = 0; i >= 0;i--)
    {
        int c = (x >> i) & 1;
        if (!nxt[p][c])  nxt[p][c] = ++cnt;
        p = nxt[p][c];
    }
}

void get(int x)
{
    int res = 0;
    for (int i = 30, p = 0; i >= 0; i--)
    {
        int c = (x >> i) & 1;

        // if (x == 5 && i == 2)  std::cout << nxt[p][0] << '\n';

        if (nxt[p][c ^ 1]) {
            p = nxt[p][c ^ 1];
            res |= (1 << i);
        }
        else   p = nxt[p][c];
    }
    ans = std::max(ans, res);
}

void solve()
{
    std::cin >> n;

    for (int i = 1;i < n;i++)
    {
        int u, v, w;    std::cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    auto dfs = [&](auto&& self, int u, int fa) -> void
        {
            insert(dis[u]);
            get(dis[u]);

            for (int i = head[u];i;i = nex[i])
            {
                int v = to[i];
                if (v == fa) continue;
                dis[v] = dis[u] ^ wei[i];
                self(self, v, u);
            }
        };

    dfs(dfs, 1, 0);
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}