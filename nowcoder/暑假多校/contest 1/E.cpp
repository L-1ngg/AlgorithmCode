#include <bits/stdc++.h>
using i64 = long long;
void solve()
{
    i64 a, b;   std::cin >> a >> b;
    i64 res = std::abs(a * a - b * b);
    std::cout << (res - 1) / 2 + std::max(res / 4 - 1, 0ll) << '\n';
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