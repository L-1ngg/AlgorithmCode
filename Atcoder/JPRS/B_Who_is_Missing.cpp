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
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(m);
    for (auto& x : a)
        std::cin >> x;
    ranges::sort(a.begin(), a.end());

    std::cout << n - m << '\n';
    for (int i = 1, j = 0; i <= n; i++)
    {
        if (j < m && a[j] == i)
        {
            j++;
            continue;
        }
        std::cout << i << " ";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}