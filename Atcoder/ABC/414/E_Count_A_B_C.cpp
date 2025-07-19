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
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 998244353;

i64 qpow(i64 x, i64 b) {
    i64 ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}
void solve()
{
    i64 n;  std::cin >> n;
    i64 inv2 = qpow(2, mod - 2);
    i64 ans = (n % mod) * ((n + 1) % mod) % mod * inv2 % mod;
    for (i64 i = 1, j;i <= n;i = j + 1) {
        j = n / (n / i);
        ans = (ans - (j - i + 1) % mod * ((n / i) % mod) % mod + mod) % mod;
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}