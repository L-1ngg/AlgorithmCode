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
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + m + 2), b(n + m + 2), c(n + m + 2), f(n + m + 2);
    for (int i = 1;i <= n + m + 1;i++)  std::cin >> a[i];
    for (int i = 1;i <= n + m + 1;i++)  std::cin >> b[i];

    int cntn = 0, cntm = 0;
    i64 sum = 0;
    int st;

    for (int i = 1;i <= n + m + 1;i++)
    {
        if (a[i] > b[i])
        {
            cntn++;
            if (cntn > n) {
                sum += b[i];
                c[i] = 2;
                st = 1;
                f[i] = 0;
            }
            else {
                sum += a[i];
                c[i] = 1;
                f[i] = 1;
            }
        }
        else {
            cntm++;
            if (cntm > m) {
                sum += a[i];
                c[i] = 1;
                st = 2;
                f[i] = 0;
            }
            else {
                sum += b[i];
                c[i] = 2;
                f[i] = 1;
            }
        }
    }

    std::vector<int> nex(n + m + 3);
    for (int i = n + m + 1;i >= 1;i--)
    {
        if (f[i]) nex[i] = nex[i + 1];
        else nex[i] = std::abs(a[i] - b[i]);
    }

    for (int i = 1;i <= n + m + 1;i++)
        std::cout << sum - (c[i] == 1 ? a[i] : b[i]) + (c[i] == st ? nex[i] : 0) << " ";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}