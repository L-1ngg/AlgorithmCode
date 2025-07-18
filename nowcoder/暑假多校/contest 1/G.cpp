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
const int mod = 1e9 + 7;

void solve()
{
    int n, q;   std::cin >> n >> q;
    std::string s;  std::cin >> s;

    while (q--) {
        std::string t;
        int a;
        std::cin >> t >> a;
        int len = t.length();
        i64 ans = 0;
        int i, j;
        for (i = 0, j = 0;i < len;i++) {
            if (s[a + i - 1] != t[i])
            {
                ans += (i64)(i - j + 1) * (i - j) / 2;
                j = i + 1;
            }
        }
        ans += (i64)(i - j + 1) * (i - j) / 2;
        std::cout << ans << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
        solve();
}