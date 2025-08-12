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
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n;i++)   std::cin >> b[i];

    if (a[n] != b[n]) {
        std::cout << "NO";
        return;
    }
    for (int i = n - 1;i >= 1;i--)
    {
        if (a[i] == b[i]) continue;
        else {
            int num1 = a[i] ^ a[i + 1];
            int num2 = a[i] ^ b[i + 1];
            if (num1 != b[i] && num2 != b[i]) {
                std::cout << "NO";
                return;
            }
        }
    }
    std::cout << "YES";
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