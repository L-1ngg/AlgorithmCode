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

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = " " + s;
    int sz = std::sqrt(n);
    if (sz * sz != n) {
        std::cout << "No\n";
        return;
    }
    for (int i = 1;i <= sz;i++)
        for (int j = 1;j <= sz;j++)
        {
            int f = 0;
            if (i == 1 || i == sz || j == 1 || j == sz) f = 1;
            if (s[(i - 1) * sz + j] - '0' != f) {
                std::cout << "No\n";
                return;
            }
        }
    std::cout << "Yes\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}