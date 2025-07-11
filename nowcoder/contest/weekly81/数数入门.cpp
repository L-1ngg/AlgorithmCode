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

int a[1005][1005];
void solve()
{
    memset(a, 0, sizeof a);
    int n;  std::cin >> n;
    bool f = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] < a[i - 1][j - 1] || a[i][j] < a[i - 1][j])
                f = 0;
        }
    std::cout << (f == 1 ? "Yes\n" : "No\n");
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