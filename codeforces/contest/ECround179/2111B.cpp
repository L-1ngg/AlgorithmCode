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
    int n, m;  std::cin >> n >> m;
    std::vector<int> f(n + 1);
    f[1] = 1, f[2] = 2;
    for (int i = 3;i <= n;i++) f[i] = f[i - 1] + f[i - 2];
    for (int i = 1;i <= m;i++)
    {
        int a, b, c;    std::cin >> a >> b >> c;
        if (a > c) std::swap(a, c);
        if (b > c) std::swap(b, c);
        if (a > b) std::swap(a, b);
        if (a >= f[n] && c >= f[n] + f[n - 1])
            std::cout << "1";
        else std::cout << "0";
    }
    std::cout << '\n';
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