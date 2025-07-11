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

//1 8 49 288 1681 9800 57121 332928 18
std::vector<int> a = { 8,49,288,1681,9800, 57121,332928 };

int square(i64 x)
{
    i64 sq = std::sqrt(x);
    return sq * sq == x;
}

void solve()
{
    i64 n;  std::cin >> n;
    i64 sum = (n + n * n) / 2;
    if (square(sum))
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<i64> b(n + 1);
    b[1] = 2, b[2] = 1;
    for (int i = 3; i <= n;i++)
        b[i] = i;
    for (int pos : a)
    {
        if (pos < n)
            std::swap(b[pos], b[pos + 1]);
    }

    for (int i = 1; i <= n; i++)
        std::cout << b[i] << ' ';
    std::cout << '\n';
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