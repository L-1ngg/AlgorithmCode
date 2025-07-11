#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

//001
void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    std::vector<i64> a(n + 1);
    std::vector<i64> suf(n + 2);
    for (int i = 1; i <= n;i++)    std::cin >> a[i];
    for (int i = n;i >= 2;i--) {
        suf[i] = suf[i + 1];
        if (s[i - 1] != s[i - 1 - 1]) suf[i] += a[i];
    }
    int cnt = 0;
    i64 pre = 0, ans = INF;
    for (int i = 1;i <= n;i++) {
        // std::cout << ans << '\n';
        i64 tmp = 0;
        if (s[i - 1] == '1' && cnt) tmp = a[i];
        if (s[i - 1] == '0' && !cnt) tmp = a[i];
        ans = std::min(ans, pre + tmp + suf[i + 1]);
        if (cnt == 0 && s[i - 1] == '1') pre += a[i], cnt = 1;
        else if (cnt == 1 && s[i - 1] == '0') pre += a[i], cnt = 0;
    }
    std::cout << std::min(pre, ans) << '\n';
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