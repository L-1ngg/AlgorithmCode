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
    int mx = 0, mn = inf;
    int cntmn = 0, cntmx = 0;
    for (int i = 1;i <= n;i++)
    {
        int x;  std::cin >> x;
        if (x < mn) cntmn = 1;
        else if (x == mn) cntmn++;
        if (x > mx) cntmx = 1;
        else if (x == mx) cntmx++;

        mx = std::max(mx, x);
        mn = std::min(mn, x);
        if (cntmn == 1 && (cntmn + cntmx == i)) std::cout << mx * 2 << " ";
        else std::cout << mx + mn << " ";
    }
    std::cout << '\n';

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}