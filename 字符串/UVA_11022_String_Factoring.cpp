#include <bits/stdc++.h>
const int inf = 1e9;
void solve()
{
    std::string s;
    while (std::cin >> s) {
        if (s == "*") break;
        int n = s.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, inf)), f(n + 1, std::vector<int>(n + 1, -1));
        auto kmp = [](std::string s) ->int {
            int len = s.length();
            std::vector<int> tmp(len + 1, 0);
            for (int i = 1, j = 0;i < len;i++) {
                while (j && s[i] != s[j]) j = tmp[j];
                j += (s[i] == s[j]);
                tmp[i + 1] = j;
            }
            return(len % (len - tmp[len]) == 0 ? (len - tmp[len]) : -1);
            };
        for (int i = 1;i <= n;i++)
            for (int j = i;j <= n;j++)
                f[i][j] = kmp(s.substr(i - 1, j - i + 1));

        for (int i = 1; i <= n;i++) dp[i][i] = 1;
        for (int len = 2;len <= n;len++) {
            for (int i = 1;i <= n - len + 1;i++) {
                int j = i + len - 1;
                if (f[i][j] != -1) dp[i][j] = dp[i][i + f[i][j] - 1];
                for (int k = i;k <= j - 1;k++)
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
        std::cout << dp[1][n] << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}