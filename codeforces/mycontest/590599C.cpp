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
    int n, c1, c2;  std::cin >> n >> c1 >> c2;
    if (c1 * 2 <= c2)
        std::cout << n * 3 * c1;
    else
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            std::string s; std::cin >> s;
            std::map<int, int> mp;
            mp[s[0] - 'A']++;
            mp[s[1] - 'A']++;
            mp[s[2] - 'A']++;
            if (c2 > c1)
            {
                if (mp.size() == 3)
                    ans += 3 * c1;
                else
                    ans += c1 + c2;
            }
            else
            {
                if (mp.size() == 3)
                    ans += 3 * c2;
                else
                    ans += 2 * c2;
            }
        }
        std::cout << ans;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}