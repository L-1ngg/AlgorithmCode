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
    int n;  std::cin >> n;
    int k;  std::cin >> k;
    std::map<int, int> a, b;
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        a[x % k]++;
    }
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        b[x % k]++;
    }
    int f = 0;
    for (auto [x, y] : a)
        if (a[x] + a[k - x] != b[x] + b[k - x]) f = 1;

    if (f)   std::cout << "NO";
    else std::cout << "YES";
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