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
    int p = n + 1;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        if (a[i] < -1 || a[i] > 1 || a[i] == 0) p = i;
    }
    int mx1 = 0, mx2 = 0, mn1 = 0, mn2 = 0;
    std::vector<int> l(n + 1), r(n + 1);
    for (int i = 1;i < p;i++)
    {
        l[i] = std::max(a[i], l[i - 1] + a[i]);
        r[i] = std::min(a[i], r[i - 1] + a[i]);
        mx1 = std::max(mx1, l[i]);
        mn1 = std::min(mn1, r[i]);
    }
    for (int i = p + 1;i <= n;i++)
    {
        l[i] = std::max(a[i], l[i - 1] + a[i]);
        r[i] = std::min(a[i], r[i - 1] + a[i]);
        mx2 = std::max(mx2, l[i]);
        mn2 = std::min(mn2, r[i]);
    }
    mn1 = std::min(mn1, mn2);
    mx1 = std::max(mx1, mx2);
    int ans = mx1 - mn1 + 1;
    std::map<int, int> mp;
    for (int i = mn1;i <= mx1;i++)
        mp[i]++;

    if (p != n + 1) {
        if (mp[a[p]]++ == 0) ans++;
        int tmp = 0;
        int mn1 = 0, mx1 = 0, mn2 = 0, mx2 = 0;
        for (int i = p + 1;i <= n;i++)
        {
            tmp += a[i];
            mn1 = std::min(mn1, tmp);
            mx1 = std::max(mx1, tmp);
        }
        tmp = 0;
        for (int i = p - 1;i >= 1;i--) {
            tmp += a[i];
            mn2 = std::min(mn2, tmp);
            mx2 = std::max(mx2, tmp);
        }
        mn1 = mn1 + mn2;
        mx1 = mx1 + mx2;
        for (int i = mn1;i <= mx1;i++)
            if (mp[i + a[p]]++ == 0) ans++;
    }
    std::cout << ans << '\n';
    for (auto [x, _] : mp)  std::cout << x << " ";
    std::cout << '\n';
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