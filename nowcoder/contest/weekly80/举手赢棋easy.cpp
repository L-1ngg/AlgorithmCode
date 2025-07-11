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
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;

    int pos = -1, cnt = 0, sum = 0;
    int mn = inf;
    for (int i = 0; i < n; i++)
    {
        sum += (s[i] == '0' ? -1 : 1);
        if (pos == -1 && s[i] == '0')
            cnt++;
        if (pos == -1 && sum < 0)
            pos = i;
        mn = std::min(mn, sum);
    }

    if (mn < -2)
        std::cout << "0";
    else if (mn >= 0)
        std::cout << n;
    else
        std::cout << cnt;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}