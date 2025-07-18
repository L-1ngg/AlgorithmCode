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
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    if (s[0] != s[n - 1]) {
        std::cout << "empty\n";
        return;
    }
    int c = 1 - (s[0] - '0');
    s = std::to_string(c) + s + std::to_string(c);
    int lst = -1, base = s[0] - '0';
    int ansp = -1, anslen = inf;
    for (int i = 0;i <= n + 1;i++) {
        if (s[i] - '0' == base && lst != -1)
        {
            if (i - lst - 1 < anslen)
            {
                anslen = i - lst - 1;
                ansp = i - anslen;
            }
        }
        lst = (s[i] - '0' == base ? i : lst);
    }

    if (anslen == 0) std::cout << "empty\n";
    else std::cout << s.substr(ansp, anslen) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}