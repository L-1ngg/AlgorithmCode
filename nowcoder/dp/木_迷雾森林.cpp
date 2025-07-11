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
const int mod = 2333;

template<class T>inline void read(T& res)
{
    char c;T flag = 1;
    while ((c = getchar()) < '0' || c > '9')if (c == '-')flag = -1;res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')res = res * 10 + c - '0';res *= flag;
}

bool a[3003][3003];
int dp[3003][3003];
void solve()
{
    int m, n;
    read(m), read(n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n;j++)
            read(a[i][j]);

    dp[m + 1][1] = 1;
    for (int i = m; i >= 1; i--)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i][j - 1] + dp[i + 1][j]) % mod;
        }
    std::cout << dp[1][n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}