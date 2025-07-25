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
    std::vector<int> a(n + 1), to(n + 1);
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        to[a[i]] = i;
    }
    int f = 1;
    for (int i = 1;i <= n;i++)
        if (a[i] != i) f = 0;
    if (f) {
        std::cout << 0 << '\n';
        return;
    }

    if (n & 1) {
        int i = (n + 1) / 2;
        int j = i;
        int l = inf, r = 0;
        while (i >= 1 && j <= n && to[i] < l && to[j] > r && to[i] <= to[j]) {
            l = to[i];
            r = to[j];
            i--, j++;
        }
        int num = j - i - 1;
        std::cout << (n - num + 1) / 2 << '\n';
    }
    else {
        int i = (n + 1) / 2;
        int j = i + 1;
        int l = inf, r = 0;
        while (i >= 1 && j <= n && to[i] < l && to[j] > r && to[i] <= to[j]) {
            l = to[i];
            r = to[j];
            i--, j++;
        }
        int num = j - i - 1;
        std::cout << (n - num + 1) / 2 << '\n';
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