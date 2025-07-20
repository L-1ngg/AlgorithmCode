#include <bits/stdc++.h>
using namespace std;
#define ranges std::ranges
#define views std::views

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using V = int;
tree<V, null_type, less<V>, rb_tree_tag, tree_order_statistics_node_update> st;

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
    int n;  std::cin >> n;
    std::vector<a3> a;
    int mn = inf, mx = 0;
    std::vector<pii> b(n + 1);
    int f = 0;
    for (int i = 1;i <= n;i++)
    {
        int l, r;   std::cin >> l >> r;
        b[i].first = l, b[i].second = r;
        if (l == 1 && r == 2 * n) f = 1;
        mn = std::min(l, mn);
        mx = std::max(r, mx);
        a.push_back({ l,0 ,i });
        a.push_back({ r,1 ,i });
    }
    if (f && n > 1) { std::cout << "NO"; return; }
    ranges::sort(a);
    // std::set<int> st;
    int ans = 0;
    for (int i = 0;i < 2 * n;i++) {
        if (st.size() == 0 && i != 0 && i != 2 * n - 1) { std::cout << "NO"; return; }
        if (a[i][1] == 0 && st.size() == 0) st.insert(b[a[i][2]].second);
        else if (a[i][1] == 0) {
            ans += st.order_of_key(b[a[i][2]].second) - st.order_of_key(a[i][0]);
            st.insert(b[a[i][2]].second);
        }
        else if (a[i][1] == 1) st.erase(a[i][0]);
    }
    std::cout << (ans == n - 1 ? "YES" : "NO");
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}