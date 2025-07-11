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
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;

    std::string a[55][55];
    for (int i = 1;i <= n; i++)
    {
        int j = n + 1 - i;
        if (i > j)
            break;
        for (int t = i; t <= j;t++)
            a[j][t] = a[i][t] = a[t][i] = a[t][j] = ((i & 1) ? "#" : ".");
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            std::cout << a[i][j];
        std::cout << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}