#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using ld = long double;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e5 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<std::vector<i64>> mp(n);
    std::vector<i64> a(n);
    for (int i = 1; i <= n;i++)
    {
        std::cin >> a[i - 1];
        mp[i - 1].assign(MAXN, 0);
        for (int j = 1; j <= a[i - 1]; j++)
        {
            int x;  std::cin >> x;
            mp[i - 1][x]++;
        }
    }

    ld ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            i64 fm = a[i] * a[j];
            i64 fz = 0;
            for (int k = 1; k < MAXN;k++)
            {
                fz += mp[i][k] * mp[j][k];
            }
            ans = std::max(ans, (ld)fz / (ld)fm);
        }
    }
    std::cout << std::fixed << std::setprecision(15) << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}