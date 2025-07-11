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

void solve()
{
    i64 n, l, r;    std::cin >> n >> l >> r;
    std::vector<int> a(n + 2);
    std::vector<int> pre(n + 2, 0);
    for (int i = 1; i <= n;i++)
    {
        std::cin >> a[i];
        pre[i] = pre[i - 1];
        pre[i] ^= a[i];
    }
    if ((n & 1) == 0)
    {
        n++;
        a[n] = pre[n >> 1];
        pre[n] = pre[n - 1] ^ a[n];
    }

    if (r <= n)
    {
        std::cout << a[r] << '\n';
        return;
    }
    else if (r > n && r <= 2 * n)
    {
        std::cout << pre[r >> 1] << '\ n';
        return;
    }
    else
    {
        auto check = [&](auto&& self, i64 x) ->int
            {
                if (x > n && x <= 2 * n)
                    return pre[x >> 1];
                if ((x >> 1) % 2 == 0)
                    return pre[n] ^ self(self, (x >> 1));
                else
                    return pre[n];
            };

        if ((r & 1))
            r--;
        std::cout << check(check, r) << '\n';
    }
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