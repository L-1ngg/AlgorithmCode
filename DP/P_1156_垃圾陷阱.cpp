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
    int n, m;   std::cin >> n >> m;
    std::vector<a3> a(m);
    for (auto& x : a) {
        std::cin >> x[0] >> x[1] >> x[2];
    }
    ranges::sort(a);
    //f[i] = x
    std::vector<int> f(n + 1, 0);
    f[0] = 10;
    for (int i = 0;i < m;i++) {
        for (int j = n;j >= 0;j--)
            if (f[j] >= a[i][0])
            {
                if (j + a[i][2] >= n) {
                    std::cout << a[i][0];
                    return;
                }
                //not eat
                f[j + a[i][2]] = std::max(f[j + a[i][2]], f[j]);
                f[j] += a[i][1];
            }
    }
    std::cout << f[0];
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