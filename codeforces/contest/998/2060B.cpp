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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(m);
    int f = 0;
    std::vector<pii> ans;
    for (int i = 1; i <= n;i++)
    {
        a.assign(m, 0);
        for (auto& x : a)
            std::cin >> x;
        ranges::sort(a);
        ans.push_back({ a[0],i });
        for (int j = 1; j < m;j++)
            if (a[j] - a[j - 1] != n)
                f = 1;
    }
    if (f) {
        std::cout << "-1\n";
        return;
    }
    ranges::sort(ans);
    for (auto [_, i] : ans)
        std::cout << i << ' ';
    std::cout << '\n';
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