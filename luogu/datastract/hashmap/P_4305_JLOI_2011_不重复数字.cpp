#include <bits/stdc++.h>
// #include <unorder_map>

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
    std::set<int> st;
    std::vector<int>  a;
    int n;  std::cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int x;  std::cin >> x;
        if (st.count(x))    continue;
        else {
            st.insert(x);   a.push_back(x);
        }
    }
    for (auto x : a)
        std::cout << x << ' ';
    std::cout << '\n';
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