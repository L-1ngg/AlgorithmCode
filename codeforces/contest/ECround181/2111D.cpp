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
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(k + 1);
    for (int i = 1;i <= k;i++)  std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());

    for (int i = 1, j = 1;i <= n;i += 2, j++) {
        for (int t = 1;t <= 3;t++)
            std::cout << a[j] << " " << a[k - j + 1] << " \n"[t == 3];
        if (i != n)
            for (int t = 1;t <= 3;t++)
                std::cout << a[k - j + 1] << " " << a[j] << " \n"[t == 3];
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