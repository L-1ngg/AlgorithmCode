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
    std::vector<int> pre(n + 1, 0), left(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        left[i] = std::min(left[i - 1], pre[i]);
    }

    int a = 0, b = 0, c = 0, d = 0;
    i64 ans = 0;
    int min = inf;
    for (int i = n; i >= 1; i--)
    {
        min = std::min(min, pre[i]);
        if (s[i - 1] == '0')
        {
            if (left[i - 1] >= 0)
                ans += a + c;
            if (left[i - 1] >= -2 && min >= -4)  a++;
            if (left[i - 1] >= 0 && min >= -2)   b++;
        }
        else
        {
            if (left[i - 1] >= 0)
                ans += b + d;
            if (left[i - 1] >= -2 && min >= -2) c++;
            if (left[i - 1] >= 0 && min >= 0) d++;
        }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}