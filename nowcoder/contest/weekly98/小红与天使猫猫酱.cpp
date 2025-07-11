// #include <bits/stdc++.h>

// #define ranges std::ranges
// #define views std::views

// using u32 = unsigned;
// using i64 = long long;
// using u64 = unsigned long long;

// using pii = std::pair<int, int>;
// using a3 = std::array<int, 3>;
// using a4 = std::array<int, 4>;

// const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
// const int N = 1e6;
// const int MAXN = 1e6 + 10;
// const int inf = 1e9;
// const i64 INF = 9114511145141919810;
// const int mod = 998244353;

// i64 qpow(i64 x, i64 b) {
//     i64 ret = 1;
//     while (b) {
//         if (b & 1) ret = ret * x % mod;
//         b >>= 1;
//         x = x * x % mod;
//     }
//     return ret;
// }

// void solve()
// {
//     i64 inv81 = qpow(81, mod - 2);
//     i64 inv9 = qpow(9, mod - 2);
//     i64 inv99 = qpow(99, mod - 2);

//     i64 n;  std::cin >> n;
//     i64 Sn_up = qpow(10, n + 1) - 10 + mod;
//     i64 sub = n * 9ll % mod;
//     Sn_up = (Sn_up - sub + mod) % mod;
//     i64 Sn = Sn_up * inv81 % mod;

//     i64 x = 100ll * inv81 % mod * inv99 % mod * (qpow(100ll, n) + mod - 1) % mod;
//     i64 y = n % mod * inv81 % mod;
//     i64 z = 2ll * inv81 % mod * inv9 % mod * 10ll % mod * (qpow(10, n) + mod - 1) % mod;
//     i64 Tn = (x + y - z + mod) % mod;
//     i64 ans = 4ll * (Sn + Tn) % mod + n % mod;
//     std::cout << ans % mod;
// }

// signed main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     solve();
// }


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
const int mod = 998244353;

i64 qpow(i64 x, i64 b) {
    i64 ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void solve()
{
    i64 inv81 = qpow(81, mod - 2);
    i64 inv9 = qpow(9, mod - 2);
    i64 inv99 = qpow(99, mod - 2);

    i64 n;  std::cin >> n;
    i64 ans = (100ll * (qpow(100, n) + mod - 1) % mod * inv81 % mod * inv99 % mod + mod) % mod;
    ans = (ans - (20ll * (qpow(10, n) + mod - 1) % mod) % mod * inv81 % mod * inv9 % mod + mod) % mod;
    ans = (ans + n % mod * inv81 % mod + mod) % mod;

    ans = (ans + 10ll * inv81 % mod * (qpow(10, n) + mod - 1) % mod + mod) % mod;
    ans = (ans - 9ll * n % mod * inv81 % mod + mod) % mod;
    ans = (4ll * ans % mod + mod) % mod;
    ans = (ans + n + mod) % mod;
    std::cout << ans;
    // std::cout << qpow(10, 3);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}