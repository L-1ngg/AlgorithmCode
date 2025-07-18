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

i64 ask1(int x, int y, int n) {
    if (n == 0) return 1;
    i64 cnt = (1 << n);
    i64 area = cnt * cnt / 4;

    int half = (1 << (n - 1));
    if (x <= half && y <= half)
        return ask1(x, y, n - 1) + area * 0;
    else if (x > half && y > half)
        return ask1(x - cnt / 2, y - cnt / 2, n - 1) + area * 1;
    else if (x <= half && y > half)
        return ask1(x, y - cnt / 2, n - 1) + area * 3;
    else if (x > half && y <= half)
        return ask1(x - cnt / 2, y, n - 1) + area * 2;
}

pii ask2(i64 num, int n) {
    if (n == 0) return { 1,1 };
    i64 cnt = (1 << n);
    i64 area = cnt * cnt / 4;

    if (num <= area) {
        auto [x, y] = ask2(num, n - 1);
        return { x,y };
    }
    else if (num <= area * 2) {
        auto [x, y] = ask2(num - area, n - 1);
        return { x + cnt / 2,y + cnt / 2 };
    }
    else if (num <= area * 3) {
        auto [x, y] = ask2(num - area * 2, n - 1);
        return { x + cnt / 2,y };
    }
    else if (num <= area * 4) {
        auto [x, y] = ask2(num - area * 3, n - 1);
        return { x,y + cnt / 2 };
    }
}
void solve()
{
    int n, q;   std::cin >> n >> q;
    while (q--) {
        std::string op; std::cin >> op;
        if (op == "->") {
            int x, y;   std::cin >> x >> y;
            std::cout << ask1(x, y, n) << '\n';
        }
        else {
            i64 x;  std::cin >> x;
            pii ans = ask2(x, n);
            std::cout << ans.first << " " << ans.second << '\n';
        }
    }
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