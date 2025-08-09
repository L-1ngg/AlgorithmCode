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
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)  std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());

    for (int i = n;i - 1 >= 1;i -= 2)
    {
        if (a[i] - a[i - 1] <= k)
        {
            k -= a[i] - a[i - 1];
            a[i - 1] = a[i];
        }
        else a[i - 1] += k, k = 0;
    }
    int f = 1;
    i64 ans = 0;
    for (int i = n;i >= 1;i--)
    {
        if (f) ans += a[i];
        else ans -= a[i];
        f ^= 1;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}