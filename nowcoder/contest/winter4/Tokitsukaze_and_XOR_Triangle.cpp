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
const int MAXN = 3e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;

int n, q;
int abit[MAXN][32][2], bbit[MAXN][32][2];
i64 sum[MAXN];

void solve()
{
    std::cin >> n >> q;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n;i++)
        std::cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 31; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                abit[i][j][k] = abit[i - 1][j][k];
                bbit[i][j][k] = bbit[i - 1][j][k];
            }
            abit[i][j][(a[i] >> j) & 1]++;
            bbit[i][j][(b[i] >> j) & 1]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1];
        for (int j = 0; j <= 31; j++)
        {
            int s = (a[i] >> j) & 1;
            sum[i] += (1ll << j) * (bbit[n][j][s ^ 1] - bbit[i - 1][j][s ^ 1]) % mod;
            sum[i] %= mod;
        }
    }

    while (q--)
    {
        int l, r;   std::cin >> l >> r;
        i64 ans = (sum[r] - sum[l - 1]);
        for (int j = 0; j <= 31; j++)
        {
            ans -= (1ll << j) * (abit[r][j][0] - abit[l - 1][j][0]) * (bbit[n][j][1] - bbit[r][j][1]);
            ans -= (1ll << j) * (abit[r][j][1] - abit[l - 1][j][1]) * (bbit[n][j][0] - bbit[r][j][0]);
            ans %= mod;
        }
        ans = (ans + mod) % mod;
        std::cout << ans << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}