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
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::vector<std::vector<int>> adj(n + 1);

    std::string ans(n + 1, '0');
    for (int i = 1; i < n; i++)
    {
        int l, r;   std::cin >> l >> r;
        if (a[l] == a[r])
        {
            // std::cout << 1 << " " << l;
            ans[a[l]] = '1';
        }
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    std::vector<int> vis(n + 1, 0);
    for (int i = 1;i <= n; i++)
    {
        for (auto x : adj[i])
        {
            int v = a[x];
            if (vis[v] == i)
                ans[v] = '1';
            vis[v] = i;
        }
    }
    std::cout << ans.substr(1) << '\n';
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