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

double A[20];
const double eps = 1e-7;
int n;

double f(double x)
{
    double ret = 0;
    for (int i = 1; i <= n + 1; i++)
        ret += A[i] * pow(x, n - i + 1);
    return ret;
}

void solve()
{

    double l, r;
    std::cin >> n >> l >> r;
    for (int i = 1; i <= n + 1; i++)
        std::cin >> A[i];

    while (r - l > eps)
    {
        double m = (l + r) / 2;
        double lm = m - eps, rm = m + eps;
        if (f(lm) > f(rm))
            r = m;
        else
            l = m;
    }

    std::cout << std::fixed << std::setprecision(6) << l;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}