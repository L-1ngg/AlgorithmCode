#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 3e5 + 10;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int pre[N], lst[N], suf[N], a[N], vis[N];
int o[N << 2], tag[N << 2];

void add(int l, int r, int root, int ml, int mr, int x)
{
    if (ml <= l && r <= mr)
    {
        o[root] += x;
        tag[root] += x;
        return;
    }
    o[root << 1] += tag[root], tag[root << 1] += tag[root];
    o[root << 1 | 1] += tag[root], tag[root << 1 | 1] += tag[root];
    tag[root] = 0;
    int mid = (l + r) >> 1;
    if (ml <= mid)  add(l, mid, root << 1, ml, mr, x);
    if (mr > mid) add(mid + 1, r, root << 1 | 1, ml, mr, x);
    o[root] = std::max(o[root << 1], o[root << 1 | 1]);
}

void solve()
{
    int n;  std::cin >> n;
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    //i and after i
    for (int i = n; i >= 1;i--)
    {
        suf[i] = suf[i + 1] + (!vis[a[i]]);
        vis[a[i]] = i;
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n;i++)
    {
        pre[i] = pre[i - 1] + (!vis[a[i]]);
        lst[i] = vis[a[i]];
        vis[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i < n;i++)
    {
        ans = std::max(ans, suf[i + 1] + o[1]);
        add(1, n, 1, i, i, pre[i]);
        add(1, n, 1, lst[i + 1], i, 1);
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}