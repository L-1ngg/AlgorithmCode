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
    if (n == 2) {
        std::cout << std::stoi(s);
        return;
    }
    if (n == 3) {
        int ans = inf;
        pii a1, a2;
        a1.first = s[0] - '0';
        a1.second = std::stoi(s.substr(1, 2));

        a2.first = s[2] - '0';
        a2.second = std::stoi(s.substr(0, 2));
        ans = std::min({ ans, a1.first + a1.second, a1.first * a1.second });
        ans = std::min({ ans, a2.first + a2.second, a2.first * a2.second });
        std::cout << ans;
        return;
    }

    if (std::count(s.begin(), s.end(), '0')) {
        std::cout << 0;
        return;
    }
    s = " " + s;

    std::vector<int> pre(n + 2), suf(n + 2);
    for (int i = 1;i <= n;i++)
    {
        pre[i] = pre[i - 1];
        if (s[i] - '0' == 1) continue;
        pre[i] += (s[i] - '0');
    }
    for (int i = n;i >= 1;i--)
    {
        suf[i] = suf[i + 1];
        if (s[i] - '0' == 1) continue;
        suf[i] += (s[i] - '0');
    }

    int ans = inf;
    for (int i = 1;i <= n - 1;i++)
    {
        int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
        ans = std::min(ans, tmp + pre[i - 1] + suf[i + 2]);
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
}