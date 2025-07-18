#include <bits/stdc++.h>
using namespace std;

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using ld = long double;

using pii = std::pair<int, int>;
using pdd = std::pair<ld, ld>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

const ld eps = 1e-8;
int sgn(ld x) {
    return fabs(x) <= eps ? 0 : (x < 0 ? -1 : 1);
}

using P = complex<ld>;
#define xx real()
#define yy imag()

void solve()
{
    int n;  std::cin >> n;
    std::vector<P> p(n + 1);
    for (int i = 1;i <= n;i++) {
        int x, y;   std::cin >> x >> y;
        p[i] = P(x, y);
    }

    int a, b, c;    std::cin >> a >> b >> c;
    if (a) {
        auto alpha = arg(P(b, -a));
        P x0(-1.0 * c / a, 0);
        for (int i = 1;i <= n;i++) {
            P tmp = p[i] - x0;
            tmp = polar(abs(tmp), arg(tmp) - alpha);
            p[i] = tmp + x0;
        }
    }
    else {
        double y0 = -1.0 * c / b;
        for (int i = 1;i <= n;i++) {
            p[i] -= P(0, y0);
        }
    }

    auto check = [&](ld x) {
        ld lmax = -1e18, rmin = 1e18;
        for (int i = 1;i <= n;i++) {
            if (sgn(x - abs(p[i].yy)) < 0) return false;
            ld d = sqrt(x * x - p[i].yy * p[i].yy);
            lmax = std::max(lmax, p[i].xx - d);
            rmin = std::min(rmin, p[i].xx + d);
            if (sgn(rmin - lmax) < 0) return false;
        }
        return true;
        };

    ld l = 0, r = 1e6;
    ld ans = 0;
    while (l <= r - eps) {
        ld mid = (l + r) / 2.0;
        if (check(mid)) ans = mid, r = mid;
        else l = mid;
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(8);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}