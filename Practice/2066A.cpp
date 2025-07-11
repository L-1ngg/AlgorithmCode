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

int ask(int l, int r) {
    std::cout << " ? " << l << " " << r << std::endl;
    int res;    std::cin >> res;
    return res;
}

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1), v(n + 1, 0);
    for (int i = 1;i <= n;i++) std::cin >> a[i];
    int mn, mx;
    for (int i = 1;i <= n;i++) {
        if (a[i] == 1) mn = i;
        if (a[i] == n) mx = i;
        v[a[i]] = 1;
    }
    for (int i = 1;i <= n;i++)
        if (!v[i]) {
            int tmp = 1;
            while (tmp == i) tmp++;
            int ret = ask(i, tmp);
            if (ret == 0)
                std::cout << "! A" << std::endl;
            else std::cout << "! B" << std::endl;
            return;
        }
    int res1 = ask(mn, mx);
    int res2 = ask(mx, mn);
    if (res1 < n - 1 || res2 < n - 1) std::cout << "! A" << std::endl;
    else std::cout << "! B" << std::endl;
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