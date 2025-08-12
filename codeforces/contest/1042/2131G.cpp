#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 60;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

std::vector<pii> f(N + 1);
std::vector<pii> pre(N + 1);
void solve()
{
    int n, k;   std::cin >> n >> k;
    i64 ans = 1;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
    for (int i = 1;i <= n;i++)
    {
        int x;  std::cin >> x;
        pq.push(x);
    }

    while (pq.size()) {
        if (k == 0) break;
        auto x = pq.top();
        pq.pop();
        if (x >= 40) {
            ans = ans * x % mod;
            for (int i = 1;i <= 39;i++) pq.push(i);
            k--;
            continue;
        }
        if (k >= f[x].first) k -= f[x].first, ans = ans * f[x].second % mod;
        else {
            for (int i = 1;i < x;i++) pq.push(i);
            ans = ans * x % mod;
            k--;
            continue;
        }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    pre[0] = { 0,1 };
    for (int i = 1;i <= N;i++)
    {
        if (i == 1) f[i].first = 1, f[i].second = 1;
        else {
            f[i].first = (pre[i - 1].first + 1);
            f[i].second = (pre[i - 1].second * i) % mod;
        }
        pre[i].first = (pre[i - 1].first + f[i].first);
        pre[i].second = (pre[i - 1].second * f[i].second) % mod;
    }
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}