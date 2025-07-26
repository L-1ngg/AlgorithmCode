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
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    i64 sum = 0;
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (n <= 2) {
        std::cout << "-1\n";
        return;
    }
    std::sort(a.begin() + 1, a.end());
    int base = n / 2 + 1;
    i64 ans = n * 2ll * a[base] - sum;
    std::cout << std::max(0ll, ans + 1) << '\n';
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