#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
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
    s = " " + s;
    std::vector<std::vector<int>> suf(n + 3, std::vector<int>(26));
    for (int i = n;i >= 1;i--)
    {
        for (int j = 0;j < 26;j++)
            suf[i][j] += suf[i + 2][j];
        suf[i][s[i] - 'a']++;
    }
    if (n % 2 == 0)
    {
        int ans = 0;
        int mx = 0;
        for (int i = 0;i < 26;i++)
            mx = std::max(mx, suf[1][i]);
        ans += n / 2 - mx;
        mx = 0;
        for (int i = 0;i < 26;i++)
            mx = std::max(mx, suf[2][i]);
        ans += n / 2 - mx;
        std::cout << ans << '\n';
        return;
    }

    std::vector<a2> cnt(26);
    int ans = inf;
    for (int i = 1;i <= n;i++)
    {
        int res = 0;
        int mx = 0;
        for (int j = 0;j < 26;j++)
            mx = std::max(mx, cnt[j][0] + suf[i + (i & 1 ? 2 : 1)][j]);
        // std::cout << mx << '\n';
        res += n / 2 - mx;
        mx = 0;
        for (int j = 0;j < 26;j++)
            mx = std::max(mx, cnt[j][1] + suf[i + (i & 1 ? 1 : 2)][j]);
        res += n / 2 - mx;
        // std::cout << mx << '\n';
        ans = std::min(ans, res);
        cnt[s[i] - 'a'][i & 1]++;
    }
    std::cout << ans + 1 << '\n';
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