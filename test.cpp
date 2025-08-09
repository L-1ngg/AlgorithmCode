#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1000;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> p(n + 1), a(n + 1), b(n + 1);
    std::vector<int> pre(n + 1);
    for (int i = 1;i <= n;i++)
    {
        std::cin >> p[i] >> a[i] >> b[i];
        pre[i] = pre[i - 1] + b[i];
    }

    std::vector dp(n + 2, std::vector<int>(N + 1, 0));
    for (int i = 1;i <= N;i++) dp[n + 1][i] = i;
    for (int i = n;i >= 1;i--) {
        for (int j = 0;j <= N;j++)
        {
            if (j > p[i]) dp[i][j] = dp[i + 1][std::max(0, j - b[i])];
            else dp[i][j] = dp[i + 1][j + a[i]];
        }
    }

    int q;  std::cin >> q;
    while (q--) {
        int x;  std::cin >> x;
        int pos = std::lower_bound(pre.begin() + 1, pre.end(), x - 500) - pre.begin();
        if (pos == n + 1) std::cout << x - pre[n] << '\n';
        else
            std::cout << dp[pos][x - pre[pos - 1]] << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}