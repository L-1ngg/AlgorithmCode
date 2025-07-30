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

//n * (lg(x)*n/x)[x:1-n]
void solve()
{
    int n, q;  std::cin >> n >> q;
    std::vector<int> cnt(n + 1);
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        cnt[x]++;
    }
    for (int i = 1;i <= n;i++) cnt[i] += cnt[i - 1];

    std::vector<int> ans(n + 1);
    for (int x = 1;x <= n;x++) {
        int l = 0, r = x - 1, res;

        auto check = [&](int m) ->bool {
            int num = 0;
            for (int i = 0;i <= n;i += x)
            {
                num += cnt[std::min(i + m, n)];
                if (i) num -= cnt[i - 1];
            }
            return num * 2 > n;
            };
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid)) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans[x] = res;
    }
    while (q--) {
        int x;  std::cin >> x;
        std::cout << ans[x] << " ";
    }
    std::cout << '\n';
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