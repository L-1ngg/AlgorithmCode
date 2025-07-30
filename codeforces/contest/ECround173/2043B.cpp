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
    int n, d;   std::cin >> n >> d;
    std::cout << 1 << " ";
    if (n >= 3)  std::cout << 3 << " ";
    else std::cout << (n * d % 3 == 0 ? "3 " : "");
    if (d == 5)  std::cout << 5 << " ";
    if (n >= 3)  std::cout << 7 << " ";
    else if ((d * 10 + d) % 7 == 0)   std::cout << 7 << " ";
    if (n >= 6)  std::cout << 9 << " ";
    else {
        int num = 1;
        while (n) {
            num *= n--;
        }
        std::cout << (num * d % 9 == 0 ? "9 " : "");
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
}