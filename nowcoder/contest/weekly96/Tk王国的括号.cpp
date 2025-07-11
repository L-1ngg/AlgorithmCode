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
const int mod = 1e9 + 7;
//97 122  65 90
void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    std::stack<int> stk;
    for (auto x : s) {
        if (stk.empty()) {
            stk.push(x);
            continue;
        }
        if (x >= 'a' && stk.top() >= 'a' && x - 'a' + stk.top() - 'a' == 25 && x > stk.top()) stk.pop();
        else  if (x <= 'Z' && stk.top() <= 'Z' && x - 'A' + stk.top() - 'A' == 25 && x < stk.top()) stk.pop();
        else stk.push(x);
    }
    std::cout << stk.size();
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