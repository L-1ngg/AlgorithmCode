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
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) std::cin >> a[i];
    std::map<int, int> mp;
    i64 ans = INF;
    int r = 1;
    i64 cost = INF; // 右边最小
    for (int i = 1;i <= n;i++) {
        while (r != n + 1 && mp[a[r]] == 0) {
            mp[a[r]]++;
            cost = std::min(cost, (i64)a[r] * (n - r + 1));
            r++;
        }
        cost = std::min(cost, (i64)a[r] * (n - r + 1));
        ans = std::min(ans, cost + std::min((i64)a[i - 1] * (i - 1), (i64)a[i] * i));
        mp[a[i]]--;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}