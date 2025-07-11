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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    std::vector<int> a11, a00, a01, a10;
    int pre1 = 0, pre0 = 0;
    for (int i = 1; i <= n;i++)
    {
        if (s[i - 1] == '1')
            pre1++;
        else pre0++;
        if (pre1 % 2 && pre0 % 2)
            a11.push_back(i);
        else if (pre1 % 2 == 0 && pre0 % 2)
            a10.push_back(i);
        else if (pre1 % 2 && pre0 % 2 == 0)
            a01.push_back(i);
        else
            a00.push_back(i);
    }

    pre1 = 0, pre0 = 0;
    int ans = 0;
    for (int i = 1; i <= n;i++) {
        if (s[i - 1] == '1')
            pre1++;
        else pre0++;
        if (pre0 % 2 == 0 && pre1 % 2 == 0)
            if (std::upper_bound(a00.begin(), a00.end(), i) != a00.end()) ans++;
        if (pre0 % 2 == 0 && pre1 % 2 == 1)
            if (std::upper_bound(a01.begin(), a01.end(), i) != a01.end()) ans++;
        if (pre0 % 2 == 1 && pre1 % 2 == 0)
            if (std::upper_bound(a10.begin(), a10.end(), i) != a10.end()) ans++;
        if (pre0 % 2 == 1 && pre1 % 2 == 1)
            if (std::upper_bound(a11.begin(), a11.end(), i) != a11.end()) ans++;
    }
    std::cout << std::fixed << std::setprecision(8) << (long double)ans / (long double)n;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}