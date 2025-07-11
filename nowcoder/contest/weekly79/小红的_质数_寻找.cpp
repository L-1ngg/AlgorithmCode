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

int a[20];
void solve()
{
    a[2] = a[3] = a[5] = a[7] = a[11] = 1;
    std::string s;
    std::cin >> s;
    std::string ans = "";
    int num = s[0] - '0';
    for (int i = num * 2; i > num;i--)
        if (a[i])
        {
            ans += std::to_string(i);
            break;
        }
    int len = s.size() - 1;
    std::string str(len, '0');
    //std::cout << ans << str << " ";
    ans += str;
    std::cout << ans << '\n';
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