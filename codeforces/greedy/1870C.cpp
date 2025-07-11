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
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1), left(n + 1, 0), right(n + 2, 0);
    std::vector<int> f(k + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        f[a[i]] = 1;
        left[i] = std::max(left[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
        right[i] = std::max(right[i + 1], a[i]);




    // for (auto it = right.rbegin();it != right.rend();it++)
    //     std::cout << *it << ' ';

    // std::cout << right[4];
    // std::cout << std::lower_bound(right.rbegin(), right.rend() - 1, 2) - right.rbegin();




    for (int i = 1; i <= k; i++)
    {
        if (!f[i])
        {
            std::cout << "0 ";
            continue;
        }
        else
        {
            int up, down = 0;
            up = std::lower_bound(left.begin(), left.end(), i) - left.begin();
            down = std::lower_bound(right.rbegin(), right.rend() - 1, i) - right.rbegin();
            down = n - down + 1;
            std::cout << (down - up + 1) * 2 << ' ';
            // std::cout << up << ' ' << down << '\n';
        }
    }
    std::cout << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;  std::cin >> t;
    while (t--)
        solve();
}