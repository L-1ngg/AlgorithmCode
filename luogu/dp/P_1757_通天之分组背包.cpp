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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int ts = 0;
int cnt[105], to[105][1000];
int a[1005], b[1005];
int dp[1005];

void solve()
{
    int m, n; std::cin >> m >> n;
    for (int i = 1; i <= n;i++)
    {
        int x;
        std::cin >> a[i] >> b[i] >> x;
        cnt[x]++;
        ts = std::max(ts, x);
        to[x][cnt[x]] = i;
    }

    for (int t = 1;t <= ts;t++)
        for (int i = m; i >= 1;i--)
            for (int j = 1; j <= cnt[t];j++)
            {
                if (i >= a[to[t][j]])
                    dp[i] = std::max(dp[i], dp[i - a[to[t][j]]] + b[to[t][j]]);
            }

    std::cout << dp[m];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}