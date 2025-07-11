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
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    int mn = inf, mx = 0;
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }
    auto check = [&](int x) -> bool {
        std::vector<int> stk;
        for (int i = 1; i <= n;i++) {
            if (a[i] >= x) stk.push_back(1);
            else stk.push_back(0);

            while (stk.size() >= 3) {
                if (stk[stk.size() - 1] == stk[stk.size() - 2] && stk[stk.size() - 2] == stk[stk.size() - 3] && stk[stk.size() - 1] == 0) {
                    stk.pop_back();
                    stk.pop_back();
                    stk.pop_back();
                    stk.push_back(0);
                }
                else if (stk[stk.size() - 2] == stk[stk.size() - 3] && stk[stk.size() - 2] == 0 && stk[stk.size() - 1] == 1) {
                    stk.pop_back();
                    stk.pop_back();
                    stk.pop_back();
                    stk.push_back(0);
                }
                else if (stk[stk.size() - 3] == stk[stk.size() - 1] && stk[stk.size() - 3] == 0 && stk[stk.size() - 2] == 1) {
                    stk.pop_back();
                    stk.pop_back();
                    stk.pop_back();
                    stk.push_back(0);
                }
                else break;
            }
        }
        // std::cout << stk.size() << " " << x << "\n";
        while (stk.size() > 1) {
            int cnt0 = 0, cnt1 = 0;
            for (int i = 1;i <= 3;i++) {
                (stk[stk.size() - 1] == 0 ? cnt0++ : cnt1++);
                stk.pop_back();
            }
            (cnt0 > cnt1 ? stk.push_back(0) : stk.push_back(1));
        }
        return stk.back();
        };

    int l = mn, r = mx, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
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