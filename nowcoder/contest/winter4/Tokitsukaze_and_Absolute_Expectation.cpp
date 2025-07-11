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
const int mod = 1e9 + 7;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)
const i64 inv3 = inv(3);

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);

    for (int i = 1;i <= n; i++)
        std::cin >> a[i] >> b[i];

    i64 answer = 0ll;
    for (int i = 2; i <= n; i++)
    {
        int l1 = a[i - 1], r1 = b[i - 1];
        int l2 = a[i], r2 = b[i];
        if (l1 > l2)
            std::swap(l1, l2), std::swap(r1, r2);

        auto cal2 = [&](int l1_, int r1_, int l2_, int r2_)
            {
                i64 ans = 0ll;
                ans += 1ll * (l2_ + r2_) * (r2_ - l2_ + 1) / 2 % mod * (r1_ - l1_ + 1);
                ans -= 1ll * (l1_ + r1_) * (r1_ - l1_ + 1) / 2 % mod * (r2_ - l2_ + 1);
                ans %= mod;
                ans = (ans + mod) % mod;
                return ans;
            };

        auto cal3 = [&](int l, int r)
            {
                int n = (r - l + 1);
                return 1ll * (n - 1) * n % mod * (n + 1) % mod * inv3 % mod;
            };

        int x = std::max(l1, l2), y = std::min(r1, r2);
        i64 res = 0;
        if (x > y)
            res += cal2(l1, r1, l2, r2);
        else
        {
            res += cal2(l1, x - 1, x, r2);
            res += cal2(x, y, y + 1, std::max(r1, r2));
            res += cal3(x, y);
            res %= mod;
        }
        i64 fm = 1ll * (r2 - l2 + 1) * (r1 - l1 + 1) % mod;
        answer = (answer + res * inv(fm)) % mod;
    }
    std::cout << answer << '\n';
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