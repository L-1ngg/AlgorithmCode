#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, V;   std::cin >> n >> V;
    std::vector<int> v(n + 1), w(n + 1), s(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> v[i] >> w[i] >> s[i];
    std::vector<int> dp(V + 1, 0);

    for (int i = 1; i <= n;i++)
    {
        if (s[i] == -1)
            for (int j = V;j >= v[i];j--)
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
        else if (s[i] == 0)
            for (int j = v[i];j <= V;j++)
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
        else {
            std::vector<pii> a;
            int base = 1;
            while (s[i] >= base) {
                a.push_back({ v[i] * base, w[i] * base });
                s[i] -= base;
                base *= 2;
            }
            if (s[i])
                a.push_back({ v[i] * s[i], w[i] * s[i] });

            for (int t = 0; t < a.size();t++)
                for (int j = V;j >= a[t].x;j--)
                    dp[j] = std::max(dp[j], dp[j - a[t].x] + a[t].y);
        }
    }
    std::cout << dp[V];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}