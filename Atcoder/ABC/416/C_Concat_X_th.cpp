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
    int n, k, x;    std::cin >> n >> k >> x;
    std::vector<std::string> a(n + 1);
    std::vector ans(k + 1, std::vector<std::string>());
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        ans[1].push_back(a[i]);
    }

    for (int i = 2;i <= k;i++) {
        for (auto x : ans[i - 1])
            for (int j = 1;j <= n;j++)
                ans[i].push_back(x + a[j]);
    }
    ranges::sort(ans[k]);
    std::cout << ans[k][x - 1];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
        solve();
}