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

#define UFLIMIT (2<<12)
int unicnt[UFLIMIT];
void ufinit(int n) {
    for (int i = 0;i < n;i++)unicnt[i] = 1;
}
int ufroot(int x) { return unicnt[x] <= 0 ? -(unicnt[x] = -ufroot(-unicnt[x])) : x; }
int ufsame(int x, int y) { return ufroot(x) == ufroot(y); }
void uni(int x, int y) {
    if ((x = ufroot(x)) == (y = ufroot(y)))return;
    if (unicnt[x] < unicnt[y]) std::swap(x, y);
    unicnt[x] += unicnt[y];
    unicnt[y] = -x;
}

void solve()
{
    int n, m, p;
    std::cin >> n >> m >> p;
    ufinit(n);
    for (int i = 1; i <= m;i++)
    {
        int x, y;   std::cin >> x >> y;
        x--, y--;
        uni(x, y);
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y;   std::cin >> x >> y;
        x--, y--;
        std::cout << (ufsame(x, y) ? "Yes\n" : "No\n");
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}