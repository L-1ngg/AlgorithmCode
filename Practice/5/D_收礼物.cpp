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
    int n, s;   std::cin >> n >> s;
    std::vector<int> a(n + 2);
    std::vector<i64> pre(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];

    int mx = 0, ans = 0;
    for (int i = 1;i <= n + 1;i++)
    {
        if (pre[i - 1] > s) break;
        int p = std::upper_bound(pre.begin(), pre.end(), s + a[i]) - pre.begin() - 1;
        if (mx <= p - 1) {
            mx = p - 1;
            ans = i;
        }
    }
    std::cout << (ans == n + 1 ? 0 : ans) << '\n';
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