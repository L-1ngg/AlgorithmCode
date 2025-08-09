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
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n;i++)   std::cin >> b[i];
    int sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1;i <= n;i++)
    {
        if (a[i] == b[i]) {
            if (a[i] == 1) cnt1++;
            else if (a[i] == -1) cnt2++;
        }
        else {
            if (a[i] > b[i]) sum1 += a[i];
            else sum2 += b[i];
        }
    }
    int l = -n, r = n, ans;
    auto check = [&](int x) {
        int get = 0;
        int need = 0;
        if (sum1 >= x) get += sum1 - x;
        else need += x - sum1;
        if (sum2 >= x) get += sum2 - x;
        else need += x - sum2;

        if (need <= cnt1 && get + cnt1 - need >= cnt2) return 1;
        else return 0;
        };
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    std::cout << ans;
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