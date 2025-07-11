#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 999999999;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    int num = n / 3 + (n >= 37);

    if (num * 3 < n)
    {
        std::cout << "Baka!";
        return;
    }
    else {
        std::vector<int> ans(n + 1);
        for (int i = 1; i <= n;i++)
        {
            ans[i] = i;
            if (i % 3 == 0)
                std::swap(ans[i - 1], ans[i]);
        }
        if (n >= 37)
            std::swap(ans[37], ans[n]);
        for (int i = 1; i <= n;i++)
            std::cout << ans[i] << " \n"[i == n];
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}