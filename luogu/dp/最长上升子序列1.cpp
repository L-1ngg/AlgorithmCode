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
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::vector<int> dp(n, inf);
    for (auto x : a)
        *std::lower_bound(dp.begin(), dp.end(), x) = x;

    int num = 0;
    for (auto x : a)
        if (x != inf)
            num++;
    std::cout << num << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}