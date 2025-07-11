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
    int n, m, k;    std::cin >> n >> m >> k;
    std::string s;  std::cin >> s;
    s = " " + s;
    std::vector<int> f(n + 2, inf);
    f[0] = 0;
    for (int i = 1;i <= n;i++)
    {
        if (s[i] == 'C') continue;
        if (s[i - 1] == 'W')
            f[i] = f[i - 1] + 1;
        for (int j = 1;j <= m;j++)
            if (i >= j && (i - j == 0 || s[i - j] == 'L')) f[i] = std::min(f[i], f[i - j]);
    }
    if (s[n] == 'W') f[n + 1] = f[n] + 1;
    for (int i = 1;i <= m;i++)
        if (n + 1 - i >= 0 && (n + 1 - i == 0 || s[n + 1 - i] == 'L')) f[n + 1] = std::min(f[n + 1], f[n + 1 - i]);

    if (f[n + 1] <= k)  std::cout << "YES\n";
    else std::cout << "NO\n";
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