#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

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
    int n, m = 1e6;
    std::cin >> n;
    std::vector<int> cnt(m + 1);
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for (int g = 1;g <= m;g++) {
        int c = 0;
        for (int j = g;j <= m;j += g)
            c += cnt[j] * j;
        ans = std::max(ans, c * g);
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}