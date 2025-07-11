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
const int mod = 1e9 + 7;

void solve()
{
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    i64 ans = 0;
    std::vector<int> before, after, now;
    for (int i = 1; i <= l - 1;i++)
        before.push_back(a[i]);
    for (int i = l; i <= r;i++)
        now.push_back(a[i]), ans += a[i];
    for (int i = r + 1; i <= n;i++)
        after.push_back(a[i]);

    ranges::sort(before);
    ranges::sort(now, std::greater<>());
    ranges::sort(after);

    i64 mx = 0ll;
    for (int i = 0; i < before.size() && i < now.size(); i++)
    {
        int c = now[i] - before[i];
        if (c > 0)
            mx += c;
        else
            break;
    }
    i64 tmp = 0ll;
    for (int i = 0; i < after.size() && i < now.size(); i++)
    {
        int c = now[i] - after[i];
        if (c > 0)
            tmp += c;
        else
            break;
    }
    mx = std::max(mx, tmp);
    std::cout << ans - mx << '\n';
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