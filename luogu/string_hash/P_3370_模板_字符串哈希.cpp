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

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

u64 base = 131;
u64 mod1 = 212370440130137957, mod2 = 1e9 + 7;

u64 get_hash1(std::string& s)
{
    u64 ans = 0;
    for (int i = 0; i < s.length();i++)
    {
        ans = (ans * base + s[i]) % mod1;
    }
    return ans;
}

u64 get_hash2(std::string& s)
{
    u64 ans = 0;
    for (int i = 0; i < s.length();i++)
    {
        ans = (ans * base + s[i]);
    }
    return ans;
}


void solve()
{
    int n;  std::cin >> n;
    std::set<puu> st;
    for (int i = 1;i <= n;i++)
    {
        std::string s;  std::cin >> s;
        u64 hash1 = get_hash1(s);
        u64 hash2 = get_hash2(s);
        st.insert({ hash1,hash2 });
    }
    std::cout << st.size();
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}