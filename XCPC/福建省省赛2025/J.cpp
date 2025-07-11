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

i64 lowbit(i64 x) {
    return x & -x;
}

void solve()
{
    i64 n;  std::cin >> n;
    std::vector<i64> ans;
    auto count = [](i64 x) {
        int cnt = 0;
        while (!(x & 1)) cnt++, x >>= 1;
        return cnt;
        };
    while (!(n == lowbit(n) && count(n) % 2 == 0)) {
        ans.push_back(lowbit(n));
        n += lowbit(n);
    }
    std::cout << ans.size() << '\n';
    for (auto x : ans)
        std::cout << x << " ";
    std::cout << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}