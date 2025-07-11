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
    int n;  std::cin >> n;
    int num = n / 7;
    int cnt = num * 5;
    int num2 = n - num * 7;
    if (num2 == 6)
        cnt += 5;
    else
        cnt += num2;
    std::cout << 3 * cnt;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}