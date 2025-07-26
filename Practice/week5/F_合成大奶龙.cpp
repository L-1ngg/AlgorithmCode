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
    std::string s1, s2; std::cin >> s1 >> s2;
    int st = -1, en = -1;
    for (int i = 0;i < n;i++)
    {
        if (s1[i] == '*' || s2[i] == '*') {
            if (st == -1)
                st = i;
            en = i;
        }
    }
    if (st == -1) {
        std::cout << 0 << "\n";
        return;
    }
    if (st == en) {
        std::cout << (s1[st] == '*' && s2[st] == '*') << "\n";
        return;
    }
    std::vector<std::vector<i64>> f(n, std::vector<i64>(2, INF));
    f[st][0] = (s2[st] == '*');
    f[st][1] = (s1[st] == '*');

    for (int i = st + 1; i <= en; ++i) {
        bool f1 = (s1[i] == '*');
        bool f2 = (s2[i] == '*');

        f[i][0] = std::min(f[i - 1][0] + 1 + f2, f[i - 1][1] + 2);
        f[i][1] = std::min(f[i - 1][1] + 1 + f1, f[i - 1][0] + 2);

        if (f1 && f2) {
            f[i][0] = std::min(f[i - 1][0], f[i - 1][1]) + 2;
            f[i][1] = std::min(f[i - 1][0], f[i - 1][1]) + 2;
        }
    }
    // std::cout << f[en][0] << " " << f[en][1];
    std::cout << std::min(f[en][0], f[en][1]) << '\n';
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
