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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

int pre2[MAXN], pre1[MAXN], a[MAXN], sum[MAXN], ans[MAXN];
std::vector<pii> q[MAXN];
int n;

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

int get(int pos)
{
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= lowbit(pos);
    }
    return res;
}

void solve()
{
    int c, m;
    n = read(), c = read(), m = read();
    for (int i = 1; i <= n;i++)
        a[i] = read();
    for (int i = 1;i <= m;i++)
    {
        int l, r;   l = read(), r = read();
        q[r].push_back({ i,l });
    }

    for (int i = 1; i <= n;i++)
    {
        if (pre2[a[i]])
        {
            add(pre2[a[i]], -1);
            add(pre1[a[i]], 1);
        }
        else if (pre1[a[i]])
        {
            add(pre1[a[i]], 1);
        }
        pre2[a[i]] = pre1[a[i]];
        pre1[a[i]] = i;
        for (auto [id, l] : q[i])
            ans[id] = get(i) - get(l - 1);
    }
    for (int i = 1; i <= m;i++)
        std::cout << ans[i] << '\n';
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