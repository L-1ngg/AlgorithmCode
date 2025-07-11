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

void solve()
{
    std::string s;  std::cin >> s;
    int cnt = 0;
    if (s[0] == 'o') cnt++;
    for (int i = 1; i < s.length();i++)
        if (s[i] == s[i - 1])
            cnt++;
    if ((cnt + s.length()) & 1)   cnt++;
    std::cout << cnt;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}