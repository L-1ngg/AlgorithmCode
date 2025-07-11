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
    std::vector<i64> a(n + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n;i++) std::cin >> a[i], pre[i] = a[i] + pre[i - 1];
    i64 mx = 0;
    for (int i = 1; i <= n;i++) {
        mx = std::max(mx, pre[i] - (i >= 10 ? pre[i - 10] : 0));
    }
    std::cout << mx << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}