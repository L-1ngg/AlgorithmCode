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
    std::vector<int> a;

    for (int i = 1; i <= n; i++)
    {
        int x;  std::cin >> x;
        a.insert(x + a.begin(), i);
    }

    std::vector<int> tree(n + 1, 0);
    std::vector<int> ans(n + 1, 0);

    auto add = [&](int i, int x)
        {
            for (; i <= n; i += i & -i)
            {
                tree[i] = std::max(tree[i], x);
            }
        };

    auto sum = [&](int i)
        {
            int res = 0;
            for (; i; i -= i & -i)
                res = std::max(res, tree[i]);
            return res;
        };

    for (int i = 0; i < n; i++)
    {
        int t = a[i];
        add(t, ans[t] = sum(t) + 1);
    }

    for (int i = 1; i <= n; i++)
        std::cout << (ans[i] = std::max(ans[i], ans[i - 1])) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}