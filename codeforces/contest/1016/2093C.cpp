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

std::string a[7] = { "1","11","111","1111","11111","111111","1111111" };
void solve()
{
    int n, k;   std::cin >> n >> k;
    auto check = [&](int x) {
        if (x < 2) return 0;
        for (int i = 2;i * i <= x;i++)
            if (x % i == 0) return 0;
        return 1;
        };

    if (k == 1)
        std::cout << (check(n) ? "YES\n" : "NO\n");
    else {
        if (n == 1)
            std::cout << (check(std::stoi(a[k - 1])) ? "YES\n" : "NO\n");
        else std::cout << "NO\n";
    }
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