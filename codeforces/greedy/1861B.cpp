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
const int mod = 1e9 + 7;

void solve()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int len = s1.size();

    for (int i = 0; i < len - 1;i++)
        if (s1[i] == s2[i] && s1[i] == '0' && s1[i + 1] == s2[i + 1] && s1[i + 1] == '1') {
            std::cout << "YES\n";
            return;
        }
    std::cout << "NO\n";
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