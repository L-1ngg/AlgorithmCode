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
    std::vector<int> p(n + 1), f(n + 1);
    std::vector<int> ans(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> p[i];
    std::string s;  std::cin >> s;
    s = " " + s;
    for (int i = 1;i <= n;i++) if (s[i] == '0') ans[i]++;
    std::iota(f.begin(), f.end(), 0);
    auto find = [&](auto&& self, int x)->int {
        return f[x] = (f[x] == x ? x : self(self, f[x]));
        };

    for (int i = 1;i <= n;i++)
    {
        int x = find(find, i), y = find(find, p[i]);
        if (x == y) continue;
        ans[x] += ans[y];
        f[y] = x;
    }
    for (int i = 1;i <= n;i++)
    {
        int x = find(find, i);
        std::cout << ans[x] << " \n"[i == n];
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}