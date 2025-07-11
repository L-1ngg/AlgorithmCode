#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int dp[45][N + 5];
int num[45][45];
void solve()
{
    std::string str;    int n;
    std::cin >> str >> n;
    int a[45], f = 0, len = 0;
    for (auto x : str) {
        if (x != '0') f = 1;
        if (f) a[++len] = x - '0';
    }
    for (int i = 1; i <= len;i++) {
        num[i][i] = a[i];
    }
    for (int i = 1; i <= len;i++)
        for (int j = i + 1; j <= len;j++) {
            if (j - i >= 15) break;
            num[i][j] += num[i][j - 1] * 10 + a[j];
        }

    memset(dp, 0x3f, sizeof dp);

    dp[0][0] = -1;
    for (int i = 1; i <= len;i++)
        for (int j = std::max(1ll, i - 14);j <= i;j++) {
            if (num[j][i] > n) continue;
            for (int k = num[j][i];k <= n;k++)
                dp[i][k] = std::min(dp[i][k], dp[j - 1][k - num[j][i]] + 1);
        }
    if (dp[len][n] >= len)  std::cout << "-1";
    else    std::cout << dp[len][n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}