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
/*
Ab3bd      Ad
db3bA      dA
*/
int dp[1001][1001];
void solve()
{
    std::string a;  std::cin >> a;
    std::string b = a;
    std::reverse(b.begin(), b.end());

    int n = a.length();
    a = " " + a;
    b = " " + b;

    dp[1][0] = dp[0][1] = dp[0][0] = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    std::cout << n - dp[n][n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}