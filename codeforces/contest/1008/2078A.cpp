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
    int n, x;   std::cin >> n >> x;
    std::vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n;i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    // std::cout << sum << '\n';
    if (sum % x == 0 && sum / x == n)    std::cout << "YES\n";
    else std::cout << "NO\n";
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