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
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];

    std::vector<int> b = a;
    ranges::sort(b);
    int x = b[k];

    std::vector<int> c;
    for (int i = 1;i <= n;i++)
        if (a[i] <= x) c.push_back(a[i]);
    a = c;
    int sz = a.size();
    int len = a.size(); //left-not use

    int l = 0, r = sz - 1;
    while (l < r) {
        int cntl = 0, cntr = 0;
        while (l < sz - 1 && a[l] == x) cntl++, l++;
        while (r >= 0 && a[r] == x) cntr++, r--;
        if (l > r) {
            std::cout << "YES\n";
            return;
        }
        if (a[l] != a[r]) {
            std::cout << "NO\n";
            return;
        }
        len -= std::abs(cntl - cntr);
        if (len < k - 1) {
            std::cout << "NO\n";
            return;
        }
        l++, r--;
    }
    std::cout << "YES\n";
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