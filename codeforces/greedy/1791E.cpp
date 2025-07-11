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
    int cnt = 0;
    std::vector<int> a(n);
    i64 mn = inf, sum = 0;
    for (auto& x : a)
    {
        std::cin >> x;
        if (x < 0)
            cnt++, x = -x;

        mn = std::min(mn, (i64)x);
        sum += x;
    }

    if (cnt & 1)
        sum -= 2 * mn;
    std::cout << sum << '\n';
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