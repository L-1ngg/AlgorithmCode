#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9e18;
const int mod = 1e9 + 7;


//内部的25
//区间的2   区间的5
//二分
void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<std::string> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];

    auto check = [&](int mid) {
        int seg = 1;
        int cnt2 = 0, cnt25 = 0;
        for (int i = 1; i <= n;i++) {
            int new2 = cnt2, new25 = cnt25;
            for (auto x : a[i]) {
                if (x == '2') new2++;
                else if (x == '5') new25 += new2;
            }
            if (new25 <= mid) {
                cnt2 = new2;
                cnt25 = new25;
            }
            else {
                seg++;
                new2 = 0;
                new25 = 0;
                for (auto x : a[i]) {
                    if (x == '2') new2++;
                    else if (x == '5') new25 += new2;
                }
                if (new25 > mid) return false;
                cnt2 = new2;
                cnt25 = new25;
            }
        }
        return seg <= k;
        };

    int l = 0, r = INF;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    std::cout << l;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}