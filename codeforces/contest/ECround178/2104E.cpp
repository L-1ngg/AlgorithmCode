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
    int n, k;   std::cin >> n >> k;
    std::string s;  std::cin >> s;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(k, n));

    for (int i = n - 1;i >= 0;--i) {
        for (int j = 0;j < k;++j)
            a[i][j] = a[i + 1][j];
        a[i][s[i] - 'a'] = i;
    }

    std::vector<int> dp(n + 2, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        int minp = n + 2;
        bool f = 0;
        for (int j = 0;j < k;j++) {
            int nex = a[i][j];
            if (nex == n) { f = 1; break; }
            else {
                minp = std::min(minp, dp[nex + 1]);
            }
        }
        if (f) dp[i] = 1;
        else dp[i] = 1 + minp;
    }

    int q;  std::cin >> q;
    while (q--) {
        std::string t;  std::cin >> t;
        int st = 0, f = 1;
        for (auto c : t) {
            int ch = c - 'a';
            if (st >= n) { f = 0;break; }
            int nex = a[st][ch];
            if (nex == n) { f = 0; break; }
            st = nex + 1;
        }
        if (!f)  std::cout << 0;
        else std::cout << dp[st];
        std::cout << '\n';
    }
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

