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
    std::vector<int> b(n + 1);
    for (int i = 1;i <= n;i++)
        std::cin >> b[i];
    std::vector<int> a, up(n + 1), down(n + 2);

    for (int i = 1; i <= n;i++) {
        if (std::lower_bound(a.begin(), a.end(), b[i]) == a.end())
            a.push_back(b[i]);
        else *std::lower_bound(a.begin(), a.end(), b[i]) = b[i];
        up[i] = a.size();
    }

    a.clear();
    for (int i = n; i >= 1;i--) {
        if (std::lower_bound(a.begin(), a.end(), b[i]) == a.end())
            a.push_back(b[i]);
        else *std::lower_bound(a.begin(), a.end(), b[i]) = b[i];
        down[i] = a.size();
    }

    int mx = 0;
    for (int i = 1; i <= n + 1;i++) {
        mx = std::max(mx, up[i - 1] + down[i]);
    }
    std::cout << n - mx;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}