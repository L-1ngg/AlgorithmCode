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
    int n, k;   std::cin >> n >> k;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    // int num = 0;
    // for (int i = 1; i <= 1e9;i++)
    //     num++;
    // // std::cout << num << '\n';
    i64 ans = 0;
    if (k == 1)
    {
        if (a[1] < a[n])
            std::swap(a[1], a[n]);
        ans += a[1];
        int mx = *max_element(a.begin() + 2, a.end());
        std::cout << ans + mx << '\n';
    }
    else if (k >= 2)
    {
        std::sort(a.begin() + 1, a.end());
        for (int i = n; i >= n - k;i--)
            ans += a[i];
        std::cout << ans << '\n';
    }


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