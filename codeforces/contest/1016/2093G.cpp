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
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    if (k == 0) {
        std::cout << "1\n";
        return;
    }

    int limit = 0, ans = inf;
    for (int j = 30;j >= 0;j--) {
        if (k & (1 << j)) {
            limit |= 1 << j;
            for (int i = 1;i <= n;i++)
                if (a[i] & (1 << j)) b[i] |= 1 << j;
        }
        else {
            std::map<int, int> mp[2];
            for (int i = 1;i <= n;i++) {
                bool flag = a[i] & (1 << j);
                if (mp[!flag].count(limit ^ b[i]))  ans = std::min(ans, i - mp[!flag][limit ^ b[i]] + 1);
                mp[flag][b[i]] = i;
            }
        }
    }
    std::map<int, int> mp;
    for (int i = 1;i <= n;i++)
    {
        if (mp.count(limit ^ b[i])) ans = std::min(ans, i - mp[limit ^ b[i]] + 1);
        mp[limit & b[i]] = i;
    }
    std::cout << (ans == inf ? -1 : ans) << '\n';
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