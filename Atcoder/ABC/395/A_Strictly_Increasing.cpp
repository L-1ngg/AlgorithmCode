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
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    int pre = 0, now = 0;
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> now;
        if (now <= pre)
            f = 0;
        pre = now;
    }
    std::cout << (f == 1 ? "Yes\n" : "No\n");
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}