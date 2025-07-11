#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 5e5 + 10;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;
const int base = 131;
const int base2 = 13331;
/*

ABAA

*/
u64 pre[N], p[N];
u64 suf[N];

u64 get_hash(u64* hash, int l, int r)
{
    return hash[r] - hash[l - 1] * p[r - l + 1];
}

void solve()
{
    std::string s;  std::cin >> s;
    int n = s.length();
    s = " " + s;
    pre[0] = 0, p[0] = 1, suf[0] = 0;
    for (int i = 1; i <= n;i++)
    {
        pre[i] = pre[i - 1] * base + s[i];
        p[i] = p[i - 1] * base;
        suf[i] = suf[i - 1] * base + s[n - i + 1];
    }

    // 1- 8
    auto check = [&](int l, int r) -> bool
        {
            if (l == r)  return 1;
            int mid;
            mid = (r - l + 1) / 2;
            if (get_hash(pre, l, l + mid - 1) == get_hash(suf, 1, mid)) {
                return 1;
            }
            return 0;
        };
    int i;
    for (i = 1;i <= n;i++)
        if (check(i, n)) break;

    std::cout << s.substr(1, n);
    for (int j = i - 1;j >= 1;j--)
        std::cout << s[j];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}