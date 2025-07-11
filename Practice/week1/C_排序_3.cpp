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
    int n, r, q;    std::cin >> n >> r >> q;
    n *= 2;
    std::vector<a3> a(n + 1);
    for (int i = 1;i <= n;i++) std::cin >> a[i][0];
    for (int i = 1;i <= n;i++) std::cin >> a[i][1], a[i][2] = i;
    std::sort(a.begin() + 1, a.end(), [](a3& n1, a3& n2) {
        if (n1[0] == n2[0])
            return n1[2] < n2[2];
        return n1[0] > n2[0];
        });
    for (int i = 1;i <= r;i++) {
        std::vector<a3> win, lose;
        for (int j = 1;j <= n;j += 2) {
            if (a[j][1] > a[j + 1][1]) {
                win.push_back({ a[j][0] + 1,a[j][1],a[j][2] });
                lose.push_back(a[j + 1]);
            }
            else {
                win.push_back({ a[j + 1][0] + 1,a[j + 1][1],a[j + 1][2] });
                lose.push_back(a[j]);
            }
        }

        int idx = 1;
        int i1 = 0, i2 = 0;
        while (i1 != win.size() && i2 != lose.size())
        {
            if (win[i1][0] > lose[i2][0] || (win[i1][0] == lose[i2][0] && win[i1][2] < lose[i2][2]))
                a[idx++] = win[i1++];
            else a[idx++] = lose[i2++];
        }
        while (i1 != win.size())     a[idx++] = win[i1++];
        while (i2 != lose.size())   a[idx++] = lose[i2++];
    }
    std::cout << a[q][2];
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