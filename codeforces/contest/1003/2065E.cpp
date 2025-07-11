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
    int n, m, k;    std::cin >> m >> n >> k;
    if (std::max(n, m) < k || std::abs(n - m) > k)
        std::cout << "-1\n";
    else
    {
        std::string s = "";
        if (n >= m)
        {
            while (k--)
                n--, s += "1";
            while (n && m)
                n--, m--, s += "01";
            while (m--)
                s += "0";
        }
        else
        {
            while (k--)
                m--, s += "0";
            while (n && m)
                n--, m--, s += "10";
            while (n--)
                s += "1";
        }
        std::cout << s << '\n';
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