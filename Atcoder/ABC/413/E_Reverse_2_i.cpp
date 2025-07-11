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
const int N = (1 << 18) + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int f[N << 1], l[N], r[N];
void solve()
{
    int n;  std::cin >> n;
    n = (1 << n);
    for (int i = 0;i < n;i++) std::cin >> f[n + i];
    for (int i = n - 1;i >= 0;i--) {
        f[i] = std::min(f[l[i] = (i << 1)], f[r[i] = (i << 1 | 1)]);
        if (f[l[i]] > f[r[i]]) std::swap(l[i], r[i]);
    }

    auto dfs = [&](auto&& self, int x) ->void {
        if (x < n) return self(self, l[x]), self(self, r[x]);
        else std::cout << f[x] << " ";
        };
    dfs(dfs, 1);
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