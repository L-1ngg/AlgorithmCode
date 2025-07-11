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
    int n, k;   std::cin >> n >> k;
    std::string s;  std::cin >> s;
    s = " " + s;
    s[0] = s[1];
    std::vector<int> a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }

    auto check = [&](int x) {
        int cnt = 0, f = 0;
        for (int i = 1; i <= n;i++)
        {
            if (s[i] == 'B' && a[i] > x && f == 0)
                f = 1, cnt++;
            if (s[i] == 'R' && a[i] > x)
                f = 0;
        }
        return cnt <= k;
        };

    int l = 0, r = mx;
    int mid = 0, res;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    std::cout << res << '\n';
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