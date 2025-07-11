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

void solve()
{
    int n, V;   std::cin >> n >> V;
    std::vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> v[i] >> w[i];

    std::vector<int> dp(V + 1);
    std::vector<int> cnt(V + 1);
    dp[0] = 0, cnt[0] = 1;
    for (int i = 1; i <= n;i++)
        for (int j = V; j >= v[i];j--)
        {
            int tmp = std::max(dp[j], dp[j - v[i]] + w[i]);
            int c = 0;
            if (tmp == dp[j]) c += cnt[j];
            if (tmp == dp[j - v[i]] + w[i]) c += cnt[j - v[i]];
            c %= mod;
            dp[j] = tmp;
            cnt[j] = c;
        }

    int mx = *max_element(dp.begin(), dp.end());
    int ans = 0;
    for (int i = 0; i <= V;i++) {
        if (dp[i] == mx)
            ans += cnt[i];
        ans %= mod;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}