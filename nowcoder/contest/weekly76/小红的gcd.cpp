#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n);
    int f1 = 0, f2 = 0;
    for (auto& x : a)
    {
        std::cin >> x;
        if (x & 1) f1 = 1;
        else    f2 = 1;
    }
    ranges::sort(a);
    int gcd = a[0];
    for (int i = 1; i < n; ++i)
    {
        gcd = std::gcd(gcd, a[i]);
        if (gcd == 1) break;
    }
    std::cout << gcd * n << "\n";

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}