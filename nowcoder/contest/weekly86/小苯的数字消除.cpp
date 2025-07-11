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
    int n;  std::cin >> n;
    std::string s;
    std::cin >> s;
    std::deque<int> dq;
    for (int i = 0;i < n;i++)
    {
        if (!dq.empty())
        {
            if (dq.back() == s[i] - '0')    dq.pop_back();
            else    dq.push_back(s[i] - '0');
        }
        else   dq.push_back(s[i] - '0');
    }
    std::cout << dq.size() / 2 << '\n';
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