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
    int n, a, b;    std::cin >> n >> a >> b;
    std::string s;  std::cin >> s;
    int cnt[2] = { 0,0 };
    std::string tmp = "1" + s;
    for (int i = 1;i <= n;i++)
        if (tmp[i] == '0' && tmp[i - 1] == '1') cnt[0]++;

    tmp = "0" + s;
    for (int i = 1;i <= n;i++)
        if (tmp[i] == '1' && tmp[i - 1] == '0') cnt[1]++;

    int mn = std::min(cnt[0] + (std::count(s.begin(), s.end(), '1') >= 1), cnt[1] + (std::count(s.begin(), s.end(), '0') >= 1));
    std::cout << a * n + (b > 0 ? b * n : b * mn) << '\n';
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