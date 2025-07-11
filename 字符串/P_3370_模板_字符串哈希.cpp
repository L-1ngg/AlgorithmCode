#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using puu = std::pair<u64, u64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;
const int base = 233;

u64 gethash1(std::string s) {
    int len = s.size();
    u64 res = 0;
    for (int i = 0; i < len;i++) {
        res = (res * base + s[i]) % mod;
    }
    return res;
}

u64 gethash2(std::string s) {
    int len = s.size();
    u64 res = 0;
    for (int i = 0; i < len;i++) {
        res = res * base + s[i];
    }
    return res;
}

void solve()
{
    int n;  std::cin >> n;
    std::set<puu> st;
    while (n--) {
        std::string  s; std::cin >> s;
        st.insert({ gethash1(s),gethash2(s) });
    }
    std::cout << st.size();
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}