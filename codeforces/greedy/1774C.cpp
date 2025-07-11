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
    int x;  std::cin >> x;
    std::string s;  std::cin >> s;
    s = " " + s;

    int num = 0;
    for (int i = 1; i < x; i++)
    {
        if (s[i] == s[i - 1])    num++;
        else    num = 0;
        std::cout << i - num << " ";
    }
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