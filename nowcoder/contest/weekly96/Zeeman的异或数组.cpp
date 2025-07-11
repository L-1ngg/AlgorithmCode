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
    std::vector<i64> a(60);
    auto insert = [&](i64 x) {
        for (int i = 59;i >= 0;i--) {
            if (x >> i & 1) {
                if (a[i])
                    x ^= a[i];
                else {
                    a[i] = x;
                    break;
                }
            }
        }
        };

    auto check = [&](i64 x) {
        for (int i = 59;i >= 0;i--) {
            if (x >> i & 1) {
                if (a[i])
                    x ^= a[i];
                else break;
            }
        }
        return x == 0;
        };

    int n;  std::cin >> n;
    for (int i = 1;i <= n;i++)
    {
        i64 x;  std::cin >> x;
        insert(x);
    }
    for (int i = 0;i <= 60;i++) {
        if (!check(1ll << i)) {
            std::cout << (1ll << i);
            return;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
}