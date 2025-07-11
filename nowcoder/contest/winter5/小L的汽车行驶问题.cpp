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

void solve()
{
    int n;std::string s;
    std::cin >> n >> s;
    i64 ans = 0;
    i64 v = 0;
    for (int i = 0; i < n; i++)
    {
        i64 tmp;
        if (s[i] == '0')
            v += 10ll;
        if (s[i] == '1')
            v = std::max(0ll, v - 5ll);
        if (s[i] == '2')
        {
            tmp = v;
            v = std::max(0ll, v - 10ll);
        }
        ans += 1ll * v;
        if (s[i] == '2')
            v = tmp;
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}