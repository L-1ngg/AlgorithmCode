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
    std::map<int, std::vector<int>> mp;
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        mp[x % k].push_back(x);
    }

    int cnt = 0;
    i64 ans = 0;
    for (auto [_, v] : mp) {
        if (v.size() & 1) cnt++;
        if (cnt == 2) {
            std::cout << -1 << '\n';
            return;
        }
        ranges::sort(v);

        if (v.size() & 1) {
            i64 l = 0, r = 0;
            for (int i = 1;i < v.size();i += 2) {
                r += (v[i + 1] - v[i]) / k;
            }
            i64 res = r;
            for (int i = 0;i < v.size() - 1;i += 2) {
                r -= (v[i + 2] - v[i + 1]) / k;
                l += (v[i + 1] - v[i]) / k;
                res = std::min(res, l + r);
            }
            ans += res;
            continue;
        }
        else {
            for (int i = 0;i < v.size() - 1;i += 2)
                ans += (v[i + 1] - v[i]) / k;
        }
    }
    std::cout << ans << '\n';
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