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
    int n, m, q;    std::cin >> n >> m >> q;
    std::vector<int> vis(n + 1);
    std::set<pii> st;

    while (q--) {
        int op, x, y;   std::cin >> op;
        if (op == 2) std::cin >> x;
        else std::cin >> x >> y;
        if (op == 2) vis[x] = 1;
        else if (op == 1)
            st.insert({ x,y });
        else {
            if (vis[x]) std::cout << "Yes\n";
            else if (st.count({ x,y })) std::cout << "Yes\n";
            else std::cout << "No\n";
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}