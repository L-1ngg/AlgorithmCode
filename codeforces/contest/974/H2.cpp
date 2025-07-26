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

std::vector<int> cnt(MAXN);
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        cnt[a[i]] = 0;
    }

    std::vector<a3> que(q + 1);
    for (int i = 1;i <= q;i++) {
        int l, r;
        std::cin >> l >> r;
        que[i] = { l,r,i };
    }
    int Knum = n / std::min<int>(n, sqrt(q));
    std::vector<int> K(n + 1);
    for (int i = 1; i <= n; i++) {
        K[i] = (i - 1) / Knum + 1;
    }
    std::sort(que.begin() + 1, que.end(), [&](auto x, auto y) {
        if (K[x[0]] != K[y[0]]) return x[0] < y[0];
        if (K[x[0]] & 1) return x[1] < y[1];
        return x[1] > y[1];
        });

    int l = 1, r = 0, val = 0;
    std::vector<int> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        auto [ql, qr, id] = que[i];
        auto add = [&](int x) -> void {
            cnt[x] ^= 1;
            if (cnt[x]) val++;
            else val--;
            };
        // auto del = [&](int x) -> void {};
        while (l > ql) add(a[--l]);
        while (r < qr) add(a[++r]);
        while (l < ql) add(a[l++]);
        while (r > qr) add(a[r--]);
        ans[id] = val;
    }
    for (int i = 1;i <= q;i++)
        std::cout << (ans[i] == 0 ? "YES\n" : "NO\n");
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