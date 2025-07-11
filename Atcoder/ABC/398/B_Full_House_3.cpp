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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int a[14] = { 0 };
    for (int i = 1; i <= 7;i++)
    {
        int x;  std::cin >> x;
        a[x]++;
    }
    int f1 = 0, f2 = 0;
    for (int i = 1; i <= 13;i++)
    {
        if (a[i] >= 3 && !f1) { f1 = 1; continue; }
        if (a[i] >= 2) f2 = 1;
    }
    if (f1 && f2)    std::cout << "Yes";
    else std::cout << "No";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}