// https://ac.nowcoder.com/acm/contest/19684/B
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
const int mod = 1e9 + 7;

int n;
int sum[MAXN], a[MAXN], pre[MAXN], ans[MAXN];
std::vector<pii> q[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void add(int pos, int x)
{
    while (pos <= n) {
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
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    int m;  std::cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int l, r;   std::cin >> l >> r;
        q[r].push_back({ i,l });
    }

    for (int i = 1;i <= n;i++)
    {
        if (pre[a[i]])
        {
            add(pre[a[i]], -1);
            add(i, 1);
            pre[a[i]] = i;
        }
        else {
            add(i, 1);
            pre[a[i]] = i;
        }
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