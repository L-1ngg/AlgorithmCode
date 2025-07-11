#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = s + s + s;

    auto cal = [&](int x) -> int {
        int ll = s[x], rr = s[x + 1];
        int l = x - 1, r = x + 2;
        if (ll == 'w') {
            int tmp = x - 1;
            while (s[tmp] == ll && tmp > x - n) tmp--;
            ll = s[tmp], l = tmp - 1;
        }
        if (rr == 'w') {
            int tmp = x + 2;
            while (s[tmp] == rr && tmp < x + n) tmp++;
            rr = s[tmp], r = tmp + 1;
        }
        while ((s[l] == 'w' || s[l] == ll) && l > x - n) l--;
        while ((s[r] == 'w' || s[r] == rr) && r < x + n) r++;
        return r - l - 1;
        };

    int ans = 0;
    for (int i = n;i < n + n;i++) {
        if (s[i] == s[i + 1]) continue;
        ans = std::max(ans, cal(i));
    }
    if (!ans) ans = n;
    std::cout << std::min(ans, n);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}