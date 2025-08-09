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
    int n, q;   std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    BIT tr(n);
    std::vector<int> ans(n + 1);

    for (int i = 1;i <= n;i++) {
        auto check = [&](int x) {
            int sum = tr.rangeAsk(1, x);
            int now = 1 + sum / x;
            return now <= a[i];
            };

        int l = 1, r = n;
        int res = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid)) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans[i] = res;
        tr.add(ans[i], 1);
    }

    // for (int i = 1;i <= n;i++)   std::cout << ans[i] << " \n"[i == n];
    while (q--) {
        int i, x;   std::cin >> i >> x;
        if (ans[i] <= x) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}