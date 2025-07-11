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
    std::stack<int> stk;
    for (int i = 1; i <= 100;i++)
        stk.push(0);

    int n;  std::cin >> n;
    while (n--)
    {
        int op, x;  std::cin >> op;
        if (op == 1)
        {
            std::cin >> x;
            stk.push(x);
        }
        else
        {
            std::cout << stk.top() << '\n';
            stk.pop();
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