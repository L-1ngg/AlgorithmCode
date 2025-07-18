#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
    }
    if (k == 1)
    {
        std::sort(a.begin() + 1, a.end());
        int mex = 0;
        for (int i = 1;i <= n;i++)
            if (a[i] == mex) mex++;
        std::cout << mex << '\n';
        return;
    }

    auto check = [&](int x) -> bool {
        int cnt = 0; std::set<int> st;
        int mex = 0;
        for (int i = 1;i <= n;i++) {
            st.insert(a[i]);
            while (st.count(mex) && mex < x) mex++;
            if (mex == x) {
                cnt++;
                mex = 0;
                st.clear();
            }
            if (cnt >= k) return 1;
        }
        return 0;
        };
    int l = 0, r = n + 1, mex = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) mex = mid, l = mid + 1;
        else r = mid - 1;
    }
    std::cout << mex << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}