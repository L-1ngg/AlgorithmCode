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
    i64 n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = " " + s;

    std::vector<int> c0(n + 1, 0);
    int mn = inf, pre = 0;
    for (int i = 1; i <= n; i++)
    {
        pre += (s[i] == '1' ? 1 : -1);
        c0[i] = c0[i - 1];
        if (s[i] == '0')
            c0[i]++;
        mn = std::min(mn, pre);
    }
    if (mn < -4)
        std::cout << 0;
    else if (mn >= 0)
        std::cout << n * (n - 1) / 2;
    else
    {
        i64 ans = 0;
        int pos1 = -1;
        int i;
        for (i = 1, pre = 0; i <= n; i++)
        {
            pre += (s[i] == '1' ? 1 : -1);
            if (pre < 0 && pos1 == -1)
            {
                pos1 = i++;
                break;
            }
        }

        // std::cout << i;
        int pos2 = -1;
        for (i;i <= n; i++)
        {
            pre += (s[i] == '1' ? 1 : -1);
            if (pre < -2 && pos2 == -1)
            {
                pos2 = i;
                break;
            }
        }

        if (pos2 == -1)
        {
            for (i = 1; i <= pos1;i++)
                if (s[i] == '0')
                    ans += (i - c0[i]) + (n - i);
        }
        else
        {
            for (i = 1; i <= pos1;i++)
                if (s[i] == '0')
                    ans += c0[pos2] - c0[i];
        }
        // std::cout << pos2 << pos1;
        std::cout << ans;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}