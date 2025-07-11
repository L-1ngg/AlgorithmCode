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
    int n, m;    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n;i++) std::cin >> a[i];
    std::vector<i64> b(n + 1);
    for (int i = n;i >= 1;i--) {
        b[i] = a[i] - a[i - 1];
        if (b[i] < 0) b[i] = 0;
    }
    for (int i = 1;i <= n;i++)
        b[i] = b[i - 1] + b[i];
    i64 k = 0;  std::cin >> k;
    for (int i = 1;i <= m;i++)
    {
        int l, r;   std::cin >> l >> r;
        std::cout << k + b[r] - b[l] << '\n';
    }
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