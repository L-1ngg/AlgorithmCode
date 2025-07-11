#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first
#define y second

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

struct mn_mx {
    int mx1, mx2, mn1, mn2;

    void fix() {
        if (mx1 < mx2) std::swap(mx1, mx2);
        if (mn1 > mn2) std::swap(mn1, mn2);
    }
    mn_mx(int a, int b) {
        mx1 = mn1 = a;
        mx2 = mn2 = b;
        fix();
    }
    void add(int x) {
        mx2 = std::max(mx2, x);
        mn2 = std::min(mn2, x);
        fix();
    }

    int len(int x) {
        return (x == mx1 ? mx2 : mx1) - (x == mn1 ? mn2 : mn1) + 1;
    }
};

void solve()
{
    int n;  std::cin >> n;
    std::vector<pii> a(n + 1);
    for (int i = 1;i <= n;i++) std::cin >> a[i].x >> a[i].y;
    if (n <= 2) {
        std::cout << n;
        return;
    }

    mn_mx X(a[1].x, a[2].x);
    mn_mx Y(a[1].y, a[2].y);
    for (int i = 3;i <= n;i++) {
        X.add(a[i].x);
        Y.add(a[i].y);
    }

    i64 mn = INF;
    for (int i = 1;i <= n;i++) {
        i64 area = (i64)X.len(a[i].x) * Y.len(a[i].y);
        mn = std::min(mn, area + (area == n - 1 ? std::min(X.len(a[i].x), Y.len(a[i].y)) : 0));
    }
    std::cout << mn;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}