#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    i64 n;  std::cin >> n;
    //二分法求解一元二次方程
    auto calc = [&](i64 a, i64 b, i64 c)
        {
            i64 l = 1, r = inf;
            i64 mid;
            while (l <= r)
            {
                mid = (l + r) >> 1;
                if (a * mid * mid + b * mid + c < 0)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            if (a * l * l + b * l + c == 0)
                return l;
            return -1ll;
        };
    //公式法求解,但是要注意爆i64问题,在数据上需要优化
    auto calc2 = [&](i64 a, i64 b, i64 c) ->i64
        {
            i64 res = 0ll;
            i64 delt = b * b - 4 * a * c;
            if ((i64)std::sqrt(delt) * (i64)std::sqrt(delt) != delt)
                return -1;
            delt = (i64)std::sqrt(delt);
            if ((-b + delt) % (2 * a) != 0)
                return -1;
            res = (-b + delt) / (2 * a);
            return res;
        };

    for (i64 d = 1; d * d * d <= n;d++)
    {
        if (n % d != 0)  continue;
        i64 p = d * d - n / d;
        if (p % 3 != 0) continue;
        i64 y = calc(1ll, d, p / 3);
        if (y > 0)
        {
            std::cout << y + d << ' ' << y;
            return;
        }
    }
    std::cout << "-1";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}