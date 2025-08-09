#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<pii> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i].second;
    for (int i = 1;i <= n;i++)   std::cin >> a[i].first;
    std::sort(a.begin() + 1, a.end());

    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    i64 lost = 0;
    for (int i = n;i >= n - k + 1;i--)
    {
        lost += a[i].second;
        pq.push(a[i].second);
    }
    std::vector<i64> pre(n + 1);
    for (int i = 1;i <= n - k;i++)
        pre[i] = pre[i - 1] + (a[i].first > a[i].second ? a[i].first - a[i].second : 0);

    i64 ans = pre[n - k] - lost;
    for (int i = n - k;i >= 1;i--)
    {
        if (pq.size())
        {
            auto mx = pq.top();
            pq.pop();
            if (a[i].second < mx) lost = lost - mx + a[i].second;
            pq.push(std::min(a[i].second, mx));
        }
        ans = std::max(ans, pre[i - 1] - lost);
    }
    std::cout << std::max(0ll, ans);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}