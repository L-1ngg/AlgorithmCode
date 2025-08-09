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
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    std::string a, b;   std::cin >> a >> b;
    int f = 1;
    int n = a.size();
    for (int i = 0;i < n;i++)
    {
        if (a[i] == b[i])   continue;
        else if (f) {
            if (a[i] - '0' < b[i] - '0') std::swap(a[i], b[i]);
            f = 0;
        }
        else {
            if (a[i] - '0' > b[i] - '0') std::swap(a[i], b[i]);
        }
    }
    std::cout << a << '\n' << b;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}