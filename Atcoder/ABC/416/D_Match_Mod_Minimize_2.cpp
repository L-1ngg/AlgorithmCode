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
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto& x : a)  std::cin >> x;
    ranges::sort(a);
    std::multiset<int> b;
    for (int i = 1;i <= n;i++)
    {
        int x;  std::cin >> x;
        b.insert(x);
    }
    i64 ans = 0;
    for (int i = n - 1;i >= 0;i--)
    {
        auto it = b.lower_bound(m - a[i]);
        if (it == b.end()) {
            for (int j = i;j >= 0;j--) ans += a[j];
            for (auto x : b)   ans += x;
            break;
        }
        ans += (a[i] + *it) % m;
        b.erase(it);
    }
    std::cout << ans << '\n';
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