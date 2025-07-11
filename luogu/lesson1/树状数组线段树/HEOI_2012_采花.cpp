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
const int MAXN = 2e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

int n, c, m;
int sum[MAXN], a[MAXN], pre[MAXN][2], ans[MAXN];
int cnt[MAXN];
std::vector<pii> q[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void add(int pos, int x)
{
    while (pos <= n)
    {
        sum[pos] += x;
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int ret = 0;
    while (pos)
    {
        ret += sum[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
void solve()
{
    std::cin >> n >> c >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int i = 1; i <= m;i++)
    {
        int l, r;   std::cin >> l >> r;
        q[r].push_back({ i,l });
    }

    for (int i = 1; i <= n;i++)
    {
        if (pre[a[i]][1])
        {
            add(pre[a[i]][1], -1);
            add(pre[a[i]][0], 1);
        }
        else if (pre[a[i]][0])
        {
            add(pre[a[i]][0], 1);
        }
        pre[a[i]][1] = pre[a[i]][0];
        pre[a[i]][0] = i;
        for (auto [id, l] : q[i])
            ans[id] = query(i) - query(l - 1);
    }

    for (int i = 1; i <= m; i++)
        std::cout << ans[i] << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}