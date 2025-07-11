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
const i64 inf = 4e18;

i64 n, k;
i64 binpow(i64 a, i64 b)
{
    i64 res = 1;
    while (b > 0)
    {
        //if (res > inf / a) return inf;
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

i64 cal(i64 x)
{
    i64 res = binpow(x, k);
    return std::abs(n - res);
}

void solve()
{
    std::cin >> n >> k;
    i64 idx_ans = inf;

    if (k == 1)
    {
        std::cout << n << '\n';
        return;
    }
    i64 l = 1ll;
    i64 r = pow(inf, 1.0 / k);
    r = std::min(r, (i64)1e18);

    while (r - l > 2)
    {
        i64 eps = (r - l) / 3;
        i64 fl = l + eps;
        i64 fr = fl + eps;
        if (cal(fl) < cal(fr))
            r = fr;
        else
            l = fl;
    }

    i64 ans = inf;
    idx_ans = std::max(1ll, l - 2);
    for (i64 i = idx_ans; i <= r; i++)
    {
        if (cal(i) < ans)
        {
            ans = cal(i);
            idx_ans = i;
        }
    }

    std::cout << idx_ans << '\n';
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