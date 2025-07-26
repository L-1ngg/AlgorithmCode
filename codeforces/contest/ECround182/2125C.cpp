#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

i64 cal(i64 n) {
    if (n == 0) {
        return 0;
    }
    i64 bad = 0;
    bad += n / 2;
    bad += n / 3;
    bad += n / 5;
    bad += n / 7;
    bad -= n / 6;
    bad -= n / 10;
    bad -= n / 14;
    bad -= n / 15;
    bad -= n / 21;
    bad -= n / 35;
    bad += n / 30;
    bad += n / 42;
    bad += n / 70;
    bad += n / 105;
    bad -= n / 210;
    return n - bad;
}
void solve()
{
    i64 l, r;   std::cin >> l >> r;
    std::cout << cal(r) - cal(l - 1) << '\n';
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