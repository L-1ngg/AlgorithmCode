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

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(2 * n + 1);
    std::vector<int> sum(2 * n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 1; i <= 2 * n; i++)
        sum[i] = a[i] + sum[i - 1];

    int dp1[405][405] = { 0 };
    int dp2[405][405] = { 0 };
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= 2 * n - len; i++)
        {
            int j = len + i - 1;
            for (int k = i; k < j; k++)
            {
                dp1[i][j] = std::max(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1]);

                if (!dp2[i][j])
                    dp2[i][j] = inf;
                dp2[i][j] = std::min(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }

    int mx = 0;
    int mn = inf;
    for (int i = 1; i <= n; i++)
    {
        mx = std::max(mx, dp1[i][i + n - 1]);
        mn = std::min(mn, dp2[i][i + n - 1]);
    }
    std::cout << mn << '\n' << mx;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}