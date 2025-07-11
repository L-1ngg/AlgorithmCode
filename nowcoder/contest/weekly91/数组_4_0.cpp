#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 2e5 + 1;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

//1 1 100
//1 2 100
void solve()
{
    int n;  std::cin >> n;
    std::map<int, int> mp;
    for (int i = 1; i <= n;i++) {
        int x;  std::cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for (auto [x, y] : mp) {
        if (!mp.count(x - 1))
        {
            ++ans;
            if (!mp.count(x + 1)) ans += y - 1;
        }
    }
    std::cout << ans - 1 << '\n';
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