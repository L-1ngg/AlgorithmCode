#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::string> a(n);
    int num = 0;
    for (auto& x : a)   std::cin >> x, num += std::count(x.begin(), x.end(), '0');
    // std::cout << num;
    if (num & 1) {
        std::cout << "-1";
        return;
    }
    std::vector<a4> ans;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m - 1;j++) {
            if (a[i][j] == '0') {
                // std::cout << i << ' ' << j << ' ' << i << ' ' << j + 1 << '\n';
                ans.push_back({ i + 1,j + 1,i + 1,j + 2 });
                a[i][j] = '1';

                if (a[i][j + 1] == '0') {
                    a[i][j + 1] = '1';
                }
                else a[i][j + 1] = '0';
            }
        }
    }

    for (int i = 0;i < n - 1;i++) {
        if (a[i][m - 1] == '0') {
            // std::cout << i << ' ' << m - 1 << ' ' << i + 1 << ' ' << m - 1 << '\n';
            ans.push_back({ i + 1,m,i + 2,m });
            a[i][m - 1] = '1';

            if (a[i + 1][m - 1] == '0') {
                a[i + 1][m - 1] = '1';
            }
            else a[i + 1][m - 1] = '0';
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [x, y, p, q] : ans)
        std::cout << x << ' ' << y << ' ' << p << ' ' << q << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}