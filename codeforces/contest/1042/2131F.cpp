#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::string a, b;   std::cin >> a >> b;
    // int n = a.size();
    a = " " + a;
    b = " " + b;
    std::vector<int> prea(n + 1);
    std::vector<int> preb(n + 1);
    for (int i = 1;i <= n;i++)
    {
        prea[i] = prea[i - 1] + (a[i] - '0');
        preb[i] = preb[i - 1] + (b[i] - '0');
    }

    std::vector<pii> c(n + 1);
    for (int i = 1; i <= n; i++) {
        i64 tmp = (i64)i - 2 * preb[i];
        c[i] = { tmp, i };
    }
    std::sort(c.begin() + 1, c.end());

    std::vector<i64> presum1(n + 1, 0);
    std::vector<i64> presum2(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int y = c[i].second;
        presum1[i] = presum1[i - 1] + preb[y];
        presum2[i] = presum2[i - 1] + ((i64)y - preb[y]);
    }

    i64 ans = 0;
    for (int x = 1; x <= n; x++) {
        i64 tmp = 2 * prea[x] - x;

        auto it = std::lower_bound(c.begin() + 1, c.end(), pii{ tmp,-1 });
        int k = it - c.begin() - 1;

        i64 res = 0;
        if (k > 0) {
            res += (i64)k * (x - prea[x]) + presum2[k];
        }
        if (k < n) {
            i64 cnt = n - k;
            res += (i64)cnt * prea[x] + (presum1[n] - presum1[k]);
        }
        ans += res;
    }

    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}