#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define col first
#define len second

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

std::vector<int> prime, minp, maxp;

void sieve(int n = 1e7) {
    minp.resize(n + 1);
    maxp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = maxp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime) {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
            maxp[i * j] = maxp[i];
        }
    }
}

std::vector<std::array<int, 2>> factorize(int n) {
    std::vector<std::array<int, 2>> ans;
    while (n > 1) {
        int now = minp[n], cnt = 0;
        while (n % now == 0) {
            n /= now;
            cnt++;
        }
        ans.push_back({ now, cnt });
    }
    return ans;
}

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> w(n + 1), c(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> w[i];
    for (int i = 1;i <= n;i++)   std::cin >> c[i];

    std::map<int, pii> dp1, dp2;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int premx = 0;
        auto fac = factorize(w[i]);

        for (auto [p, _] : fac) {
            if (c[i] != dp1[p].col) premx = std::max(premx, dp1[p].len);
            else premx = std::max(premx, dp2[p].len);
        }
        int now = premx + 1;
        ans = std::max(ans, now);

        for (auto [p, _] : fac) {
            if (c[i] == dp1[p].col) dp1[p].len = std::max(dp1[p].len, now);
            else {
                if (now > dp1[p].len) {
                    dp2[p] = dp1[p];
                    dp1[p] = { c[i],now };
                }
                else if (now > dp2[p].len) {
                    dp2[p] = { c[i],now };
                }
            }
        }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    sieve(5e5 + 10);
    while (t--)
        solve();
}