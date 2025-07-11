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
    int n, r, c;    std::cin >> n >> r >> c;
    std::string s;  std::cin >> s;
    s = " " + s;

    int x = 0, y = 0;
    std::set<pii> st;
    for (int i = 1; i <= n;i++)
    {
        st.insert({ x,y });
        if (s[i] == 'N')
            x += 1, r += 1;
        else if (s[i] == 'S')
            x -= 1, r -= 1;
        else if (s[i] == 'E')
            y -= 1, c -= 1;
        else
            y += 1, c += 1;
        if (st.count({ r,c }))
            std::cout << 1;
        else std::cout << 0;
    }
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