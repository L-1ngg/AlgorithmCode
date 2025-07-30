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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    i64 l, r;   std::cin >> l >> r;

    i64 L = 1, R = r - l + 1, ans = 0;

    auto check = [&](i64 x) {
        return l + (1 + x) * x / 2 <= r;
        };
    while (L <= R) {
        i64 mid = L + R >> 1;
        if (check(mid)) L = mid + 1, ans = mid;
        else R = mid - 1;
    }
    std::cout << ans + 1 << '\n';
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