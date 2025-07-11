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
// const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;

namespace NTT
{
    const i64 g = 3;
    const i64 p = 998244353;
    i64 wn[35];
    i64 pow2(i64 a, i64 b)
    {
        i64 res = 1;
        while (b)
        {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }
    void getwn()
    {
        for (int i = 0; i < 25; i++) wn[i] = pow2(g, (p - 1) / (1LL << i));
    }
    void ntt(i64* a, int len, int f)
    {
        i64 i, j = 0, t, k, w, id;
        for (i = 1; i < len - 1; i++)
        {
            for (t = len; j ^= t >>= 1, ~j & t;);
            if (i < j) std::swap(a[i], a[j]);
        }
        for (i = 1, id = 1; i < len; i <<= 1, id++)
        {
            t = i << 1;
            for (j = 0; j < len; j += t)
            {
                for (k = 0, w = 1; k < i; k++, w = w * wn[id] % p)
                {
                    i64 x = a[j + k], y = w * a[j + k + i] % p;
                    a[j + k] = (x + y) % p;
                    a[j + k + i] = (x - y + p) % p;
                }
            }
        }
        if (f)
        {
            for (i = 1, j = len - 1; i < j; i++, j--) std::swap(a[i], a[j]);
            i64 inv = pow2(len, p - 2);
            for (i = 0; i < len; i++) a[i] = a[i] * inv % p;
        }
    }
    void mul(i64* a, i64* b, int l1, int l2)
    {
        int len, i;
        for (len = 1; len <= l1 + l2; len <<= 1);
        for (i = l1 + 1; i <= len; i++) a[i] = 0;
        for (i = l2 + 1; i <= len; i++) b[i] = 0;
        ntt(a, len, 0); ntt(b, len, 0);
        for (i = 0; i < len; i++) a[i] = a[i] * b[i] % p;
        ntt(a, len, 1);
    }
};


const int MAXN = 300005;
const i64 mod = 998244353;
int n;
i64 a[MAXN], inv[MAXN], ki[MAXN], k;


void init(i64 n)
{
    inv[0] = inv[1] = 1;
    for (i64 i = 2; i <= n; i++)
    {
        inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
    }
    return;
}


void get_ki(i64 k, int len)
{
    //当一个数做k次前缀和k > mod时,会有循环,循环节为mod
    //而由于前缀和和差分的关系,可以将k次差分看成-k次前缀和,然后mod下
    k = (k % mod + mod) % mod;
    ki[0] = 1;
    for (int i = 1; i < len; ++i)
    {
        ki[i] = ki[i - 1] * inv[i] % mod * ((k + i - 1) % mod) % mod;
    }
}

void solve()
{
    NTT::getwn();
    init(100000);
    i64 n, k;
    std::cin >> n >> k;
    get_ki(k, n);

    for (int i = 0; i < n; i++)
        std::cout << ki[i] << ' ';
    // for (int i = 0; i < n; i++)
//     std::cin >> a[i];

// NTT::mul(a, ki, n, n);
// for (int i = 0; i < n; i++)
//     std::cout << a[i] << " ";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}