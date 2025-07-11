#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

// const int N = 1e6;
const int MAXN = 1e5 + 10;
// const int inf = 1e9;
// const i64 INF = 9114511145141919810;
const int base = 131;
// const int mod = 1e9 + 7;

u64 p[MAXN];
u64 s[MAXN], t[MAXN];
int n, m;

u64 str_h(u64* hash, int l, int r)
{
    return (hash[r] - hash[l - 1] * p[r - l + 1]);
}
//r为可以匹配的最大长度
int lcp(int x, int  y, int r)
{
    int l = 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (str_h(s, x, x + mid - 1) != str_h(t, y, y + mid - 1))
            r = mid - 1;
        else l = mid + 1;
    }
    return r;
}

bool check(int x)
{
    int y = 1, r = x + m - 1, l;
    for (int i = 1; i <= 3; i++)
    {
        l = lcp(x, y, m - y + 1);
        x += l + 1;
        y += l + 1;
        if (y > m) return 1;
    }
    return str_h(s, x, r) == str_h(t, y, m);
}

void solve()
{
    std::string str, ttr;   std::cin >> str >> ttr;
    n = str.length();
    m = ttr.length();
    str = " " + str;
    ttr = " " + ttr;

    s[0] = t[0] = 0;
    for (int i = 1;i <= n;i++)
        s[i] = s[i - 1] * base + str[i];
    for (int i = 1; i <= m;i++)
        t[i] = t[i - 1] * base + ttr[i];

    int ans = 0;
    for (int i = 1; i <= n - m + 1;i++)
        if (check(i)) {
            ans++;
            //std::cout << i << '\n'; 
        }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    p[0] = 1;
    for (int i = 1; i <= MAXN;i++) {
        p[i] = p[i - 1] * base;
    }

    int t_;
    std::cin >> t_;
    while (t_--)
        solve();
}