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
    int n, m;   std::cin >> n >> m;

    //a[i]表示i个鸽子所在的编号,b[i]表示第i个箱子所在的编号,c[i]表示编号i对应的箱子号
    std::vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n;i++)
        a[i] = b[i] = c[i] = i;
    while (m--)
    {
        int op; std::cin >> op;
        if (op == 1)
        {
            int gezi, to;   std::cin >> gezi >> to;
            a[gezi] = b[to];
        }
        else if (op == 2)
        {
            int sw1, sw2;
            std::cin >> sw1 >> sw2;
            std::swap(b[sw1], b[sw2]);
            std::swap(c[b[sw1]], c[b[sw2]]);
        }
        else
        {
            int gezi;   std::cin >> gezi;
            std::cout << c[a[gezi]] << '\n';
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}