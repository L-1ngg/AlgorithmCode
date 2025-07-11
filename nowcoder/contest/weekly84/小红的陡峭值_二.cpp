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
    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    ranges::sort(a);

    int ans = 0;
    for (int i = 1; i < n;i++)
        ans += a[i] - a[i - 1];
    if (ans == 0)
        std::cout << 1 << ' ' << ans;
    else
        std::cout << 2 << ' ' << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}