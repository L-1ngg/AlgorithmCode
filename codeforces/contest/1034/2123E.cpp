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
    std::vector<int> cnt(n + 1, 0);
    for (int i = 1;i <= n;i++)
    {
        int x;  std::cin >> x;
        cnt[x]++;
    }
    int mex = 0;
    while (cnt[mex]) mex++;
    std::vector<int> vis(n + 1, 0);
    std::vector<std::vector<int>> a(n + 1);
    for (int i = 0;i <= mex;i++)
        a[cnt[i]].push_back(i);

    std::priority_queue<int> pq;
    for (int i = 0;i <= n;i++)
    {
        int mx = std::min(mex, n - i);
        for (auto x : a[i]) pq.push(x);
        while (!pq.empty() && pq.top() >= mx) pq.pop();
        std::cout << pq.size() + 1 << " ";
    }
    std::cout << '\n';
}
// 2 2 1
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}