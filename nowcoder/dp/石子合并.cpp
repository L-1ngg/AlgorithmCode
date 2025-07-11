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
const int inf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<i64> a(2 * n + 1), pre(2 * n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 1; i <= 2 * n; i++)
        pre[i] = pre[i - 1] + a[i];

    std::vector<std::vector<i64>> mxdp(2 * n + 1, std::vector<i64>(2 * n + 1, 0)), mndp(2 * n + 1, std::vector<i64>(2 * n + 1, inf));

    for (int i = 1; i <= 2 * n; i++)
        mndp[i][i] = 0;

    for (int len = 2; len <= n;len++)
        for (int i = 1; i <= 2 * n - len; i++)
        {
            int j = len - 1 + i;
            for (int k = i; k < j; k++)
            {
                mxdp[i][j] = std::max(mxdp[i][j], mxdp[i][k] + mxdp[k + 1][j] + pre[j] - pre[i - 1]);
                mndp[i][j] = std::min(mndp[i][j], mndp[i][k] + mndp[k + 1][j] + pre[j] - pre[i - 1]);
            }
        }

    i64 mxans = 0, mnans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        mxans = std::max(mxans, mxdp[i][i + n - 1]);
        mnans = std::min(mnans, mndp[i][i + n - 1]);
    }
    std::cout << mnans << '\n' << mxans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}