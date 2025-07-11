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
    std::map<int, int> mp;

    bool f = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;  std::cin >> x;
        if (mp[x])
            f = 1;
        mp[x] = i;
    }
    std::cout << (f == 1 ? "NO\n" : "YES\n");
    if (!f)
        for (auto [u, v] : mp)
            std::cout << v << ' ';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}