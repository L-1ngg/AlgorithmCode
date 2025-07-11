#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = (1 << 9);
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

i64 dp[10][N][100];
int n, k;

void solve()
{
    std::cin >> n >> k;
    std::vector<int> sta{ 0 }, cnt{ 0 };
    int len;
    for (int i = 0; i < (1 << n);i++) {
        if (i & (i << 1)) continue;
        sta.push_back(i);
        cnt.push_back(__builtin_popcount(i));
        len = sta.size() - 1;
        dp[1][len][cnt[len]] = 1;
    }

    for (int i = 2;i <= n;i++) {
        for (int p = 1; p <= len;p++)
            for (int q = 1; q <= len;q++) {
                if (sta[p] & sta[q]) continue;
                if (sta[p] & (sta[q] << 1)) continue;
                if ((sta[p] << 1) & sta[q]) continue;
                for (int j = cnt[p]; j <= k;j++)
                    dp[i][p][j] += dp[i - 1][q][j - cnt[p]];
            }
    }
    i64 ans = 0;
    for (int i = 1;i <= len;i++)
        ans += (dp[n][i][k]);
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}