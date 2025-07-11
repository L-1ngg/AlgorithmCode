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

/*
https://codeforces.com/problemset/problem/1844/C
*/
void solve()
{
    int n;  std::cin >> n;
    std::vector<i64>  a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    i64 ans = -inf, res1 = 0, res2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            if (a[i] > 0)
                res1 += a[i];
        }
        else
            if (a[i] > 0)
                res2 += a[i];
    }
    ans = std::max(res1, res2);
    if (res1 <= 0 && res2 <= 0)
        ans = *max_element(a.begin() + 1, a.end());
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