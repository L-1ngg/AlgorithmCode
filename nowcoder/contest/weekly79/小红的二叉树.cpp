#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e4 + 10;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

i64 a[N];
void solve()
{
    a[1] = 0, a[2] = 1ll;
    for (int i = 3; i <= 1e4; i++)
        a[i] = (a[i - 1] * 2 + 5) % mod;

    int n;  std::cin >> n;
    std::cout << a[n];
}
/*
2 1
3 7
*/
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}