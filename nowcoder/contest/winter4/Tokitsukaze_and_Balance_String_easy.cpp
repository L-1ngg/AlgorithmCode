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
const int mod = 1e9 + 7;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;

    if (n == 1)
    {
        if (s[0] != '?')
            std::cout << 1 << '\n';
        else
            std::cout << 2 << '\n';
        return;
    }
    i64 cnt = std::count(s.begin(), s.end(), '?');
    i64 ans = 0;
    if (s[0] != '?' && s[n - 1] != '?' && s[0] != s[n - 1])
        ans += 2 * qpow(2, cnt) % mod;
    else if (s[0] != '?' && s[n - 1] != '?' && s[0] == s[n - 1])
        ans += (n - 2) * qpow(2, cnt) % mod;
    else if (s[0] == s[n - 1])
    {
        ans += 2 * (n - 2) * qpow(2, cnt - 2) % mod;
        ans += 2 * 2 * qpow(2, cnt - 2) % mod;
    }
    else if (s[0] != s[n - 1])
    {
        ans += (n - 2) * qpow(2, cnt - 1) % mod;
        ans += 2 * qpow(2, cnt - 1) % mod;
    }
    std::cout << ans << '\n';
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