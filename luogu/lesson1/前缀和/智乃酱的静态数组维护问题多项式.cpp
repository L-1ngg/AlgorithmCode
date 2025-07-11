#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 10 + 5;
const int MAXN = 1e5 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

i64 a[MAXN];
i64 suf1[N], suf2[N], c[N];

void P(i64 a[], int len, int cnt)
{
    while (cnt--)
    {
        for (int i = 1; i <= len;i++)
            a[i] = (a[i - 1] + a[i]) % mod;
    }
}

void D(i64 a[], int len, int cnt)
{
    while (cnt--)
    {
        for (int i = len; i >= 1;i--)
        {
            a[i] = (a[i] - a[i - 1]);
            if (a[i] < 0) a[i] += mod;
        }
    }
}

i64 F(i64 x, i64 c[], int k)
{
    i64 res = 0;
    i64 base = 1;
    for (int i = k;i >= 0;i--)
    {
        res += base * c[i] % mod;
        res %= mod;
        base = base * x % mod;
    }
    return res;
}

i64 g(i64 x, i64 c[], int l, int r, int k)
{
    return (mod - F(x + (r - l + 1), c, k) % mod);
}


void solve()
{
    int n, m, q;
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    D(a, n, 6);
    while (m--)
    {
        int l, r, k;    std::cin >> l >> r >> k;
        for (int i = 0; i <= k; i++)
            std::cin >> c[i];
        for (int i = 1; i <= 10; i++)
        {
            suf1[i] = F(i, c, k);
            suf2[i] = g(i, c, l, r, k);
        }
        D(suf1, 10, 6);
        D(suf2, 10, 6);
        for (int i = 1; i <= 10;i++)
        {
            a[i + l - 1] += suf1[i];
            a[i + l - 1] %= mod;
            a[r + i] += suf2[i];
            a[r + i] %= mod;
        }
    }
    P(a, n, 7);
    while (q--)
    {
        int l, r;   std::cin >> l >> r;
        std::cout << (a[r] - a[l - 1] + mod) % mod << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}