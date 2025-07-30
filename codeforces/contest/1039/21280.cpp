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
    int n, c;  std::cin >> n >> c;
    std::vector<int> a;
    int ans = 0;
    i64 base = 1;
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        if (x > c) ans++;
        else a.push_back(x);
    }
    ranges::sort(a);
    for (int i = a.size() - 1;i >= 0;i--)
    {
        if ((i64)a[i] * base > c) ans++;
        else base *= 2;
    }
    std::cout << ans << '\n';
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