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
    std::vector<i64> a(n + 1);
    i64 sum = 0, mx = 0;
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        sum += a[i];
        mx = std::max(mx, a[i]);
    }
    if (sum & 1 || mx > sum / 2) {
        std::cout << "-1\n";
        return;
    }
    i64 res = 0, del = 0;
    for (int i = 1;i <= n;i++) {
        res += a[i];
        if (res >= sum / 2) {
            del = res - (sum - res);
            break;
        }
    }

    if (!del) {
        std::cout << "1\n";
        for (int i = 1;i <= n;i++)
            std::cout << a[i] << " \n"[i == n];
        return;
    }

    std::cout << "2\n";
    //1
    int i = 1;
    for (int cnt = 1;cnt <= 2;cnt++)
    {
        i64 tmp = del / 2;
        while (tmp) {
            i64 jian = std::min(a[i], tmp);
            std::cout << jian << " ";
            tmp -= jian;
            a[i] -= jian;
            i++;
        }
    }
    for (;i <= n;i++)
        std::cout << 0 << " \n"[i == n];
    //2
    for (int i = 1;i <= n;i++)
        std::cout << a[i] << " \n"[i == n];
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