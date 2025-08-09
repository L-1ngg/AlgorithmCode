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
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> R(2 * n + 1, 0), nex(2 * n + 1, -1);
    for (int i = 1;i <= n;i++) {
        int l, r;   std::cin >> l >> r;
        if (r > R[l]) {
            R[l] = r;
            nex[l] = i;
        }
    }
    std::vector<int> ans;
    for (int i = 1;i <= 2 * n;i++)
        if (nex[i] != -1) ans.push_back(nex[i]);
    std::cout << ans.size() << '\n';
    for (auto x : ans) std::cout << x << " ";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}