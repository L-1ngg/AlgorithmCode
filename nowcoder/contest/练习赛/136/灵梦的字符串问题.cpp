#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
// #define int long long    

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 2e5 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    i64 n, m;   std::cin >> n >> m;
    std::string s;  std::cin >> s;
    s = " " + s;
    std::vector<i64> a(n + 1);
    i64 min = INF;
    for (int i = 1; i <= n;i++)
        std::cin >> a[i], min = std::min(min, a[i]);

    if (min > m)
    {
        std::cout << s.substr(1) << '\n';
        return;
    }
    std::vector<char> suf(n + 1);
    suf[n] = s[n];
    for (int i = n - 1; i >= 1;i--)
    {
        if (s[i] == s[i + 1]) suf[i] = suf[i + 1];
        else suf[i] = s[i + 1];
    }
    if (suf[1] == s[1])
    {
        std::cout << s.substr(1) << '\n';
        return;
    }

    std::vector<a3> b;
    int id = 0;
    for (int i = 1;i <= n;i++)
    {
        if (suf[i] == s[i])
            break;
        if (s[i] != s[i - 1]) id++;
        if (a[i] <= m && s[i] <= suf[i])
            b.emplace_back(a3{ id,a[i],i });
    }
    std::sort(b.begin(), b.end(), [&](a3& n1, a3& n2) {
        if (n1[0] == n2[0])
            return n1[1] < n2[1];
        return n1[0] < n2[0];
        });

    std::vector<int> vis(n + 1, 0);
    for (int i = 0; i < b.size();i++)
    {
        if (m >= b[i][1])
        {
            m -= b[i][1];
            vis[b[i][2]] = 1;
        }
    }

    for (int i = 1;i <= n;i++)
    {
        std::cout << s[i];
        if (vis[i])
            std::cout << s[i];
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}