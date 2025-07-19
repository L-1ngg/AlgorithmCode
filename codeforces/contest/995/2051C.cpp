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
    int n, m, k;    std::cin >> n >> m >> k;
    std::vector<int> a(m + 1);
    for (int i = 1;i <= m;i++)   std::cin >> a[i];
    std::vector<int> know(k + 1);
    for (int i = 1;i <= k;i++)   std::cin >> know[i];
    std::string ans = "";
    if (n == k) {
        for (int i = 1;i <= m;i++)
            ans += "1";
        std::cout << ans << '\n';
    }
    else if (n - k >= 2) {
        for (int i = 1;i <= m;i++)
            ans += "0";
        std::cout << ans << '\n';
    }
    else {
        std::sort(know.begin() + 1, know.end());
        int no = 1;
        for (int i = 1;i <= k;i++, no++) if (know[i] != no) break;
        for (int i = 1;i <= m;i++) {
            if (a[i] == no) ans += "1";
            else ans += "0";
        }
        std::cout << ans << '\n';
    }
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