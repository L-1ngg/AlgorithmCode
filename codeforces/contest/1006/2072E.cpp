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

/*
100 100
x   (x)*(x-1)/2
*/
void solve()
{
    int n;  std::cin >> n;
    if (n == 0)  std::cout << "0\n";
    else {
        auto check = [&](int x)
            {
                int l = 0, r = 500;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (mid * (mid - 1) / 2 <= x)
                        l = mid + 1;
                    else r = mid - 1;
                }
                return r;
            };

        int ans = 0, x = 0, y = 0;
        std::vector<pii> a;
        while (n)
        {
            int num = check(n);
            ans += num;
            n -= (num * (num - 1) / 2);

            for (int i = 1; i <= num;i++, y++)
                a.push_back({ x, y });
            x++;
        }
        std::cout << ans << '\n';
        for (auto [x, y] : a)
            std::cout << x << ' ' << y << '\n';
    }
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