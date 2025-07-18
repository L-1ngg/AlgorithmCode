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

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n;i++)   std::cin >> b[i];
    if (a[n] == b[n]) {
        std::cout << n << '\n';
        return;
    }
    std::map<int, int> mp1, mp2;
    mp1[a[n]] = n;
    mp2[b[n]] = n;
    int ans = 0;
    for (int i = n - 1;i >= 1;i--) {
        if (a[i] == b[i]) {
            ans = i;
            break;
        }
        if ((n - i) & 1) {
            if (mp1[a[i]] || mp2[b[i]]) {
                ans = i;
                break;
            }
            if ((mp1[b[i]] && mp1[b[i]] != i + 1) || (mp2[a[i]] && mp2[a[i]] != i + 1)) {
                ans = i;
                break;
            }
            mp1[b[i]] = std::max(mp1[b[i]], i);
            mp2[a[i]] = std::max(mp2[a[i]], i);
        }
        else {
            if (mp2[a[i]] || mp1[b[i]]) {
                ans = i;
                break;
            }
            if ((mp2[b[i]] && mp2[b[i]] != i + 1) || (mp1[a[i]] && mp1[a[i]] != i + 1)) {
                ans = i;
                break;
            }
            mp2[b[i]] = std::max(mp2[b[i]], i);
            mp1[a[i]] = std::max(mp1[a[i]], i);
        }
    }
    std::cout << ans << '\n';
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