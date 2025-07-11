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

void solve()
{
    // int n = 1;
    // while (n++ <= 100)
    int n;  std::cin >> n;
    //{
    int mx = n / 2;
    int mn = 0;
    mn = n / 3;
    if (n % 3 == 2)
        mn++;
    std::cout << mn << " " << mx << '\n';
    //}
}
// 1 1 1 1 1 1 1 1
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}