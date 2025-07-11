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

std::set<char> st;
std::set<char> std_st;

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) continue;
        st = std_st;
        st.erase(s[i - 1]);
        if (i + 1 < n) st.erase(s[i + 1]);
        s[i] = *st.begin();
    }
    std::cout << s << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std_st.insert('r');
    std_st.insert('e');
    std_st.insert('d');
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}