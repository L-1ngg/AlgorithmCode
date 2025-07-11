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
const int MAXN = 1e5 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = " " + s;
    std::vector<int> a(n + 1, 0);
    i64 ans = 0;
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    for (int i = 1, j = -1; i <= n; i++)
    {
        if (s[i] == '0')
            j = i;
        else if (j >= 0 && a[j] > a[i])
        {
            std::swap(s[i], s[j]);
            j = i;
        }
    }

    for (int i = 1; i <= n; i++)
        if (s[i] == '1')
            ans += a[i];
    std::cout << ans << '\n';
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