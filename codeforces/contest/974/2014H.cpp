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

std::vector<u64> h(N + 1);
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<u64> pre(n + 1);
    for (int i = 1;i <= n;i++) {
        u64 x;  std::cin >> x;
        pre[i] ^= pre[i - 1] ^ h[x];
    }
    while (q--) {
        int l, r;   std::cin >> l >> r;
        std::cout << ((pre[r] == pre[l - 1]) ? "YES\n" : "NO\n");
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::mt19937_64 rnd(time(0));
    for (int i = 1;i <= N;i++) {
        h[i] = rnd();
    }
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}