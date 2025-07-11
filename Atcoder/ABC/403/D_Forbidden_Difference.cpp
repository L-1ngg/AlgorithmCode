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
    int n, d;  std::cin >> n >> d;
    std::vector<int> a(n);
    for (auto& x : a)   std::cin >> x;

    if (d == 0) {
        std::sort(a.begin(), a.end());
        std::cout << a.end() - std::unique(a.begin(), a.end()) << '\n';
        return;
    }

    std::sort(a.begin(), a.end(), [&](int i, int j) {
        return pii{ i % d,i } < pii{ j % d,j };
        });

    int lst = -d - 1;
    int dp0 = 0, dp1 = 0; // 删除,保留      
    for (int l = 0, r = 0; r < n;l = r) {
        while (r < n && a[l] == a[r]) r++;
        if (a[l] - lst == d) {
            std::tie(dp0, dp1) = std::pair(std::max(dp0, dp1), dp0 + r - l);
        }
        else {
            dp0 = std::max(dp0, dp1);
            dp1 = dp0 + r - l;
        }
        lst = a[l];
    }
    std::cout << n - std::max(dp0, dp1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}