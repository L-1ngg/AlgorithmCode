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
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    std::vector<i64> l(n + 1), r(n + 1);
    std::vector<i64> nl(n + 1), nr(n + 2);
    for (int i = 1;i <= n;i++) r[i] = r[i - 1] + a[i];
    for (int i = 1;i <= n;i++) l[i] = l[i - 1] + a[n - i + 1];

    nl[1] = 0;
    for (int i = 2;i <= n;i++)
    {
        if (a[i] != a[i - 1]) nl[i] = i - 1;
        else nl[i] = nl[i - 1];
    }
    nr[n] = nr[n + 1] = n + 1;
    for (int i = n - 1;i >= 1;i--)
    {
        if (a[i] != a[i + 1]) nr[i] = i + 1;
        else nr[i] = nr[i + 1];
    }

    std::vector<int> ans(n + 1, 0);
    for (int i = 1;i <= n;i++) {
        if (i > 1 && a[i] < a[i - 1]) { ans[i] = 1; continue; }
        if (i < n && a[i] < a[i + 1]) { ans[i] = 1; continue; }

        if (nl[i - 1] == 0 && nr[i + 1] == n + 1) { ans[i] = -1; continue; }

        int res = n + 1;
        if (nl[i - 1] != 0) {
            int L = n - nl[i - 1] + 1, R = n;
            while (L <= R) {
                int mid = L + R >> 1;
                if (l[mid] > l[n - i + 1] + a[i]) res = std::min(res, mid - (n - i + 1)), R = mid - 1;
                else L = mid + 1;
            }
        }
        if (nr[i + 1] != n + 1) {
            int L = nr[i + 1], R = n;
            while (L <= R) {
                int mid = L + R >> 1;
                if (r[mid] > r[i] + a[i]) res = std::min(res, mid - i), R = mid - 1;
                else L = mid + 1;
            }
        }
        if (res == n + 1) ans[i] = -1;
        else ans[i] = res;
    }
    for (int i = 1;i <= n;i++)   std::cout << ans[i] << " ";
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