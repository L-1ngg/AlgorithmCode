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

struct BIT {
    std::vector<i64> w;
    int n;
    BIT(int n) : n(n), w(n + 1) {}
    void add(int x, i64 v) {
        for (; x <= n; x += x & -x) {
            w[x] += v;
        }
    }
    i64 rangeAsk(int l, int r) { // 差分实现区间和查询
        auto ask = [&](int x) {
            i64 ans = 0;
            for (; x; x -= x & -x) {
                ans += w[x];
            }
            return ans;
            };
        return ask(r) - ask(l - 1);
    }
};

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;

    int m = 2 * n + 20;
    BIT tr(m + 1);
    int zero = n + 10;
    i64 ans = 0, res = 0;

    for (auto c : s) {
        if (c == '1') {
            res += tr.rangeAsk(1, zero);
            res++;
            zero++;
            tr.add(zero - 1, 1);
        }
        else {
            res += tr.rangeAsk(zero, m);
            res++;
            zero--;
            tr.add(zero + 1, 1);
        }
        ans += res;
    }
    std::cout << ans << '\n';
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