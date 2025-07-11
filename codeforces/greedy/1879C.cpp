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
const int mod = 998244353;

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

std::vector<int> fact(1, 1);
std::vector<int> inv_fact(1, 1);

auto get_fact(int x, bool inv = 0) {
    while ((int)fact.size() < x + 1) {
        fact.push_back(1ll * fact.back() * fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return (inv ? inv_fact[x] : fact[x]);
}

auto get_inv_fact(int x) { return get_fact(x, 1); }

i64 C(int n, int k) {
    if (k<0 || k>n)return 0;
    return 1ll * get_fact(n) * get_inv_fact(k) % mod * get_inv_fact(n - k) % mod;
}

i64 A(int n, int k) {
    // if (n == 0) return 1;
    return 1ll * get_fact(n) * get_inv_fact(n - k) % mod;
}

i64 F(int n) { return get_fact(n); }

void solve()
{
    std::string s;  std::cin >> s;
    s = s + "e";
    int n = s.length();

    char c;
    c = s[0];
    int num = 1, ans1 = 0;
    i64 ans2 = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == c) num++;
        else {
            c = s[i];
            ans1 += (num - 1);
            if (num)   ans2 = (ans2 * num) % mod;
            num = 1;
        }
    }
    std::cout << ans1 << ' ' << ans2 * F(ans1) % mod << '\n';
    // std::cout << A(3, 3);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t; std::cin >> t;
    while (t--)
        solve();
}