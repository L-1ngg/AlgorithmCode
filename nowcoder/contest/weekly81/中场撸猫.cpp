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

std::vector<std::vector<int>> a;
std::vector<std::vector<int>> b;

void solve()
{
    int n;  std::cin >> n;
    a.assign(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n;j++)
            std::cin >> a[i][j];
        ranges::sort(a[i].begin() + 1, a[i].end());
    }

    int ans = 1;
    bool f = 0;
    b.assign(n + 1, std::vector<int>(n + 1));
    b[1][1] = a[1][1];
    for (int i = 2; i <= n;i++)
    {
        int j;
        auto it = std::lower_bound(a[i].begin(), a[i].end(), b[i - 1][1]);
        if (it == a[i].end())
            break;
        for (j = 1; j <= i && it != a[i].end(); j++, it++)
        {
            while (it != a[i].end()) {
                if (*it >= b[i - 1][j - 1] && *it >= b[i - 1][j])
                {
                    b[i][j] = *it;
                    break;
                }
                else
                    it++;
                if (it == a[i].end())
                    f = 1;
            }
            if (f)
                break;
        }
        if (f)
            break;
        if (it == a[i].end() && j <= i)
            break;
        ans++;
    }
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