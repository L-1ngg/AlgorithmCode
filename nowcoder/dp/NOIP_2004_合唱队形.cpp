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
    std::vector<int> a(n + 5);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::vector<int> dp1(n + 5), dp2(n + 5);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                dp1[i] = std::max(dp1[i], dp1[j] + 1);
            if (a[n + 1 - i] > a[n + 1 - j])
                dp2[n + 1 - i] = std::max(dp2[n + 1 - i], dp2[n + 1 - j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, dp1[i] + dp2[i]);
    std::cout << n - 1 - ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}