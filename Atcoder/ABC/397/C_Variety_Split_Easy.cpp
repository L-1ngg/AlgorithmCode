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
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    std::vector<int> pre(n + 1, 0), suf(n + 2, 0);
    std::set<int> st;
    for (int i = 1; i <= n;i++)
    {
        pre[i] = pre[i - 1];
        if (!st.count(a[i]))
        {
            st.insert(a[i]);
            pre[i]++;
        }
    }
    st.clear();
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1];
        if (!st.count(a[i]))
        {
            st.insert(a[i]);
            suf[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        ans = std::max(ans, pre[i] + suf[i + 1]);
    }
    std::cout << ans;
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