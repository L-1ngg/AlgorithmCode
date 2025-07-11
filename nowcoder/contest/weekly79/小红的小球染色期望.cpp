#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

i64 qpow(i64 x, i64 k)
{
    i64 ret = 1;
    while (k)
    {
        if (k & 1) ret = ret * x % mod;
        k >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

i64 dp[N] = { 0 }, pre[N] = { 0 };
void solve()
{
    int n;  std::cin >> n;

    dp[2] = 1, pre[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (inv(i - 1) * 2 * pre[i - 2]) % mod;
        dp[i] = (dp[i] + 1) % mod;
        pre[i] = (pre[i - 1] + dp[i]) % mod;
    }

    std::cout << dp[n] << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}