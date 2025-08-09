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
const int mod = 998244353;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    i64 sum = 0;
    for (int i = 1;i <= n;i++)   std::cin >> a[i], sum += a[i];
    std::sort(a.begin() + 1, a.end());

    i64 ans = 0;
    std::vector<i64> f(sum + 1, 0);
    f[0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = sum;j >= a[i];j--)
        {
            int mn = std::max(a[i], (j + 1) / 2);
            int res = f[j - a[i]] * mn % mod;
            ans = (ans + res) % mod;
            f[j] += f[j - a[i]];
            f[j] %= mod;
        }
    }
    std::cout << ans;
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