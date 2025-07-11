/*
x + y   2 * x + 2 * y

*/
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
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    int mn = inf;
    for (int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        mn = std::min(a[i], mn);
    }
    if (n == 1)
    {
        std::cout << a[1] * 2;
        return;
    }
    std::vector<int> leaf(n + 1, 0);
    for (int i = 1; i <= n - 1;i++) {
        int u, v;   std::cin >> u >> v;
        leaf[u]++;
        leaf[v]++;
    }

    int f = 0;
    i64 sum = 0;
    for (int i = 1; i <= n;i++)
        if (leaf[i] == 1) f ^= 1, sum += a[i];

    if (f) sum += mn;
    std::cout << sum;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}