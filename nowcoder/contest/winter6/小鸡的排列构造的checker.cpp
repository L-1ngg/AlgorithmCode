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
    std::vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n;i++)
    {
        std::cin >> p[i];
        pos[p[i]] = i;;
    }

    std::vector<a3> q(m + 1);
    std::vector<std::vector<int>> record(n + 1);

    for (int i = 1; i <= m; i++)
    {
        std::cin >> q[i][0] >> q[i][1] >> q[i][2];
        record[p[q[i][2]]].push_back(i);
    }

    std::vector<int> bit(n + 1);
    auto add = [&](int i)
        {
            for (; i <= n; i += (i & -i))
                bit[i] += 1;
        };

    auto sum = [&](int i)
        {
            int res = 0;
            for (;i;i -= (i & -i))
                res += bit[i];
            return res;
        };

    std::vector<int> ans(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto j : record[i])
            ans[j] = sum(q[j][1]) - sum(q[j][0] - 1) + q[j][0];
        add(pos[i]);
    }
    for (int i = 1; i <= m; i++)
        std::cout << ans[i] << '\n';
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