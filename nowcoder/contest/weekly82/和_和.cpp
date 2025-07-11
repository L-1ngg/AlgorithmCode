#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

i64 pre[MAXN], suf[MAXN];
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    std::priority_queue<int> pq;
    i64 res = 0;
    for (int i = 1; i <= m; i++)
    {
        res += a[i];
        pq.push(a[i]);
        pre[i] = res;
    }
    for (int i = m + 1; i <= n - m;i++)
    {
        if (a[i] < pq.top())
        {
            res = res - pq.top() + a[i];
            pq.pop();
            pq.push(a[i]);
        }
        pre[i] = res;
    }



    while (!pq.empty())
        pq.pop();
    res = 0;
    for (int i = n; i >= n - m + 1; i--)
    {
        res += b[i];
        pq.push(b[i]);
        suf[i] = res;
    }
    for (int i = n - m; i >= m + 1;i--)
    {
        if (b[i] < pq.top())
        {
            res = res - pq.top() + b[i];
            pq.pop();
            pq.push(b[i]);
        }
        suf[i] = res;
    }

    // std::cout << suf[2] << '\n';

    i64 min = inf;
    for (int i = m; i <= n - m; i++)
    {
        min = std::min(min, pre[i] + suf[i + 1]);
    }
    std::cout << min << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}