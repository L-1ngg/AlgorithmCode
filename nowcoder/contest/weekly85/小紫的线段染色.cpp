#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;
using P = std::pair<a3, int>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<a3> a(n + 1, { 0,0,0 });
    for (int i = 1; i <= n;i++) {
        std::cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    std::sort(a.begin() + 1, a.end(), [&](a3 n1, a3 n2) {
        return n1[0] < n2[0];
        });

    std::vector<pii> d;
    for (int i = 1; i <= n;i++)
    {
        d.push_back({ a[i][0],1 });
        d.push_back({ a[i][1] + 1,-1 });
    }
    ranges::sort(d);
    int sum = 0;
    for (auto [pos, x] : d)
    {
        sum += x;
        if (sum >= 3)
        {
            std::cout << "-1\n";
            return;
        }
    }

    std::vector<int> vis(n + 1, 0);
    std::vector<int> ans;
    int lst = 0, lsti = 0;

    for (int i = 1; i <= n;i++) {
        if (a[i][0] <= lst && !vis[lsti])
        {
            ans.push_back(a[i][2]);
            vis[i] = 1;
        }
        if (a[i][1] > lst)
        {
            lst = std::max(lst, a[i][1]);
            lsti = i;
        }
    }

    if (ans.size() == 0)
    {
        std::cout << "1\n" << n;
        return;
    }
    std::cout << ans.size() << '\n';
    for (auto x : ans)
        std::cout << x << " ";
    std::cout << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}