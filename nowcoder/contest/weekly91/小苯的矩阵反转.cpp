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

int a[1003][1003];
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::string> v(n + 1);
    std::vector<int> r(n + 1), c(m + 1);
    int c1 = 0;

    for (int i = 1; i <= n;i++)
        std::cin >> v[i];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
        {
            a[i][j] = v[i][j - 1] - '0';
            if (a[i][j]) c1++, r[i]++, c[j]++;;
        }

    int Cc = 0, Cr = 0;
    for (int i = 1; i <= n;i++)
        Cr += (r[i] == m);
    for (int i = 1; i <= m;i++)
        Cc += (c[i] == n);

    if (c1 == 0 || (Cr == 2 && c1 == 2 * m) || (Cc == 2 && c1 == 2 * n)) {
        std::cout << "YES\n";
        return;
    }
    if (c1 != n + m - 2) {
        std::cout << "NO\n";
        return;
    }

    bool ok = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1;j <= m;j++) {
            if (a[i][j]) continue;
            if (r[i] == m - 1 && c[j] == n - 1) ok = 1;
        }
    std::cout << (ok == 1 ? "YES\n" : "NO\n");
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