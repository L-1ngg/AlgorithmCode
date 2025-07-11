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
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n;i++)  std::cin >> a[i];

    std::vector<int> f(n + 1, 0);
    for (int i = n;i >= 1;i--) {
        if (f[i]) continue;
        int d = std::__lg(i) + 1;

        while (1) {
            int need = (1 << d) - 1;
            int j = i ^ need;
            if (j >= 1 && j <= n && !f[j]) {
                f[i] = j;
                f[j] = i;
                break;
            }
            d--;
        }
    }
    for (int i = 1; i <= n;i++) {
        std::cout << f[a[i]] << " ";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}