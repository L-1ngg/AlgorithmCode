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

    std::vector<pii> v;
    int ans = 0;
    int cur = 0;
    auto work = [&](int d) {
        while (v.size() && cur < d) {
            auto& [x, a] = v.back();
            if (cur > x + k - 1) {
                v.clear();
                continue;
            }
            if (a >= m)
            {
                int r = std::min({ d - 1, cur + a / m - 1 , x + k - 1 });
                ans += r - cur + 1;
                a -= (r - cur + 1) * m;
                cur = r + 1;
                continue;
            }
            int need = m;
            while (v.size() && need) {
                auto& [x, a] = v.back();
                if (cur > x + k - 1) {
                    v.clear();
                    continue;
                }
                if (a <= need) {
                    need -= a;
                    v.pop_back();
                }
                else {
                    a -= need;
                    need = 0;
                }
            }
            if (need == 0) ans++;
            cur++;
        }
        cur = d;
        };

    for (int i = 1;i <= n;i++)
    {
        int d, a;   std::cin >> d >> a;
        work(d);
        v.push_back({ d,a });
    }
    work(1e8);
    std::cout << ans << '\n';
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