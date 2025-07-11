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
    std::deque<pii> a;
    for (int i = 1;i <= n;i++) {
        int op; std::cin >> op;
        if (op == 1) {
            int c, x;   std::cin >> c >> x;
            a.push_back({ c,x });
        }
        else {
            int cnt;  std::cin >> cnt;
            i64 sum = 0;
            while (cnt) {
                auto [c, x] = a.front();
                a.pop_front();
                if (c > cnt) {
                    sum += (i64)cnt * x;
                    a.push_front({ c - cnt,x });
                    cnt = 0;
                }
                else {
                    sum += (i64)c * x;
                    cnt -= c;
                }
            }
            std::cout << sum << '\n';
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}