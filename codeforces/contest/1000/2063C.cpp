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
    std::vector<std::vector<int>> a(n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;   std::cin >> u >> v;
        a[--u].push_back(--v);
        a[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (auto j : a[i])
            ans = std::max(ans, (int)(a[i].size() + a[j].size() - 2));

    std::multiset<int> s;
    for (auto x : a)
        s.insert(x.size());
    for (int i = 0; i < n; i++)
    {
        s.erase(s.find(a[i].size()));
        for (auto j : a[i])
            s.erase(s.find(a[j].size()));
        if (!s.empty())
            ans = std::max(ans, (int)(a[i].size() + *s.rbegin() - 1));
        s.insert(a[i].size());
        for (auto j : a[i])
            s.insert(a[j].size());
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