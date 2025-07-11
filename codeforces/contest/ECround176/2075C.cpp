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
    i64 n, m;   std::cin >> n >> m;
    std::vector<i64> a(m + 1, 0);
    for (int i = 1;i <= m;i++)
    {
        std::cin >> a[i];
        //最关键的易错点,a[i]若为n,会导致公式出错
        a[i] = std::min(a[i], n - 1);
    }
    std::sort(a.begin(), a.end());

    int j = m;
    i64 suf = 0, ans = 0;
    for (int i = 1; i <= m;i++)
    {
        while (j >= 1 && a[i] + a[j] >= n) {
            suf += a[j];
            j--;
        }
        ans += suf + (i64)(m - j) * (a[i] - n + 1);
    }
    for (int i = 1; i <= m;i++)
    {
        if (a[i] * 2 >= n)
            ans -= (a[i] * 2 - n + 1);
    }
    std::cout << ans << '\n';
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