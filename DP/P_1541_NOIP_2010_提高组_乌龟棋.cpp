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
const int N = 40 + 1;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int f[N][N][N][N];
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    a4 cnt = {};
    for (int i = 1;i <= m;i++) {
        int x;  std::cin >> x;
        cnt[x - 1]++;
    }
    f[0][0][0][0] = a[1];
    for (int i = 0;i <= cnt[0];i++)
        for (int j = 0;j <= cnt[1];j++)
            for (int p = 0;p <= cnt[2];p++)
                for (int q = 0;q <= cnt[3];q++)
                {
                    int pos = i + 2 * j + 3 * p + 4 * q + 1;
                    if (i)  f[i][j][p][q] = std::max(f[i][j][p][q], f[i - 1][j][p][q] + a[pos]);
                    if (j)  f[i][j][p][q] = std::max(f[i][j][p][q], f[i][j - 1][p][q] + a[pos]);
                    if (p)  f[i][j][p][q] = std::max(f[i][j][p][q], f[i][j][p - 1][q] + a[pos]);
                    if (q)  f[i][j][p][q] = std::max(f[i][j][p][q], f[i][j][p][q - 1] + a[pos]);
                }
    std::cout << f[cnt[0]][cnt[1]][cnt[2]][cnt[3]];
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