#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second
#define int long long

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
    i64 n, k;   std::cin >> n >> k;
    auto check = [&](i64 x)
        {
            i64 l = 1, r = n;
            i64 m;
            while (l <= r)
            {
                m = (l + r) >> 1;
                if ((m + 1) * m / 2 >= x)
                    r = m - 1;
                else
                    l = m + 1;
            }
            return l;
        };

    std::map<int, std::vector<pii>> mp;
    for (int i = 1; i <= k; i++)
    {
        i64 x;  std::cin >> x;
        int step = check(x);
        mp[step].emplace_back(x, x);
    }

    std::vector<std::vector<pii>> a;
    std::vector<int> step;

    for (auto [x, v] : mp)
    {
        step.emplace_back(x);
        a.emplace_back(v);
    }

    std::reverse(step.begin(), step.end());
    std::reverse(a.begin(), a.end());

    i64 ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        auto v = a[i];
        int down = step[i], up = 0;

        ranges::sort(v.begin(), v.end());
        std::vector<pii> merge;

        //区间合并
        for (auto [l, r] : v)
        {
            if (merge.size() && merge.back().y + 1 >= l)
                merge.back().y = std::max(merge.back().y, r);
            else
                merge.emplace_back(l, r);
        }

        if (i + 1 < a.size())
            up = step[i + 1];

        for (auto [l, r] : merge)
        {
            int len = r - l + 1;
            if (up <= down - len)
                ans += (1 + len) * len / 2;
            else
            {
                int h = down - up;
                i64 nl = l - (h * down - (h + 1) * h / 2);
                i64 nr = nl + len - h - 1;
                i64 d1 = (nr - nl + 1 + 1);
                i64 d2 = len;
                ans += (d1 + d2) * h / 2;
                if (i + 1 < a.size())
                    a[i + 1].emplace_back(nl, nr);
            }
        }
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