#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second 

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, X;   std::cin >> n >> X;
    i64 sum = 0;
    std::vector<pii> a(n + 1);

    std::set<pii> st;

    for (int i = 1; i <= n;i++)
    {
        std::cin >> a[i].x >> a[i].y;
        sum += a[i].x + a[i].y;
        st.insert({ a[i].x, i });
    }

    std::vector<int> vis(n + 1, 0);
    while (!st.empty())
    {
        auto [num, pos] = *st.begin();
        st.erase(st.begin());
        vis[pos] = 1;
        if (pos - 1 >= 1 && !vis[pos - 1])
        {
            a[pos - 1].x = std::min(a[pos - 1].x, num + X);
            st.insert({ a[pos - 1].x,pos - 1 });
        }
        if (pos + 1 <= n && !vis[pos + 1])
        {
            a[pos + 1].x = std::min(a[pos + 1].x, num + X);
            st.insert({ a[pos + 1].x,pos + 1 });
        }
    }

    i64 min = inf;
    for (int i = 1; i <= n;i++)
        min = std::min(min, a[i].x + a[i].y);

    std::cout << sum - min * n;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}