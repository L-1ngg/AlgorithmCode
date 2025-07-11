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

int a[105][105];
int cnt1[105], cnt2[105];
void solve()
{
    int n, m;   std::cin >> n >> m;

    memset(a, 0, sizeof a);
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
        {
            char c; std::cin >> c;
            a[i][j] = c - '0';
        }

    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
            if (a[i][j] == 1)
                cnt1[i]++;
        cnt1[i] %= 2;
        if (cnt1[i]) num1++;
    }
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1;j <= n;j++)
            if (a[j][i] == 1)
                cnt2[i]++;
        cnt2[i] %= 2;
        if (cnt2[i]) num2++;
    }

    std::cout << std::max(num1, num2) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;  std::cin >> t;
    while (t--)
        solve();
}