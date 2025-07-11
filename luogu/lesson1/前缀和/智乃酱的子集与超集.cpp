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
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n;i++)
        std::cin >> a[i];

    std::vector<i64>  pre(1 << n), suf(1 << n);

    for (int i = 0; i < (1 << n);i++)
    {
        int sum = 0;
        for (int j = 0; j < n;j++)
            if (i >> j & 1)  sum ^= a[j];
        pre[i] = sum;
        suf[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << n);j++)
        {
            if (j >> i & 1)    pre[j] = pre[j] + pre[j ^ (1 << i)];
            else suf[j] += suf[j ^ (1 << i)];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int x;  std::cin >> x;
        int status = 0;
        for (int j = 1; j <= x;j++)
        {
            int tmp;    std::cin >> tmp;
            tmp--;
            status |= (1 << tmp);
        }
        std::cout << pre[status] << ' ' << suf[status] << '\n';
    }
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