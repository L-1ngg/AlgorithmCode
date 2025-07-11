/*
3 2 1
3 4 3

2 3 2

6 12 6
*/
#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

// 2 1 3
void solve()
{
    int n;  std::cin >> n;
    std::vector<pii> a(n);
    std::vector<int> b(n);
    for (int i = 0; i < n;i++)  std::cin >> a[i].x, a[i].x *= (i + 1), a[i].y = i;
    for (int i = 0; i < n;i++)  std::cin >> b[i];

    std::sort(a.rbegin(), a.rend());
    std::sort(b.rbegin(), b.rend());
    std::vector<int> ans(n);
    for (int i = 0; i < n;i++) {
        ans[a[i].y] = b[i];
    }
    for (auto x : ans)
        std::cout << x << ' ';

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}