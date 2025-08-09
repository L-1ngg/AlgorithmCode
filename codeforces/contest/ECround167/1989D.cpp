#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
// #define int long long

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

std::vector<int> ans(N + 1, 0);
std::vector<int> to(N + 1, 0);

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<pii> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i].second;
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        a[i].first = a[i].second - x;
    }

    std::sort(a.begin() + 1, a.end(), [&](pii& p1, pii& p2) {
        return p1.first < p2.first;
        });

    int j = 1;
    for (int i = N;i >= 1;i--) {
        while (j <= n && a[j].second > i) j++;
        if (j > n) break;
        to[i] = a[j].first;
    }

    for (int i = 1;i <= N;i++) {
        ans[i] = ans[i - 1];
        if (to[i]) ans[i] = std::max(ans[i], ans[i - to[i]] + 1);
    }

    i64 res = 0;
    for (int i = 1;i <= m;i++)
    {
        int x;  std::cin >> x;
        if (x > N) {
            res += (x - a[1].second + a[1].first - 1) / a[1].first;
            x -= (x - a[1].second + a[1].first - 1) / a[1].first * a[1].first;
        }
        res += ans[x];
    }
    std::cout << res * 2;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}