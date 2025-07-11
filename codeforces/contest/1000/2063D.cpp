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
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto& x : a)
        std::cin >> x;
    for (auto& x : b)
        std::cin >> x;

    ranges::sort(a), ranges::sort(b);
    std::vector<i64> asum(n + 1, 0), bsum(m + 1, 0);
    for (int i = 1; i <= n / 2; i++)
        asum[i] = asum[i - 1] + (a[n - i] - a[i - 1]);
    for (int i = 1; i <= m / 2; i++)
        bsum[i] = bsum[i - 1] + (b[m - i] - b[i - 1]);

    std::vector<i64> ans = { 0 };
    for (int k = 1; 3 * k <= m + n; k++)
    {
        int L = std::max(0, 2 * k - m);
        int R = std::min(k, n - k);
        if (L > R) continue;
        auto f = [&](int kx) {return asum[kx] + bsum[k - kx];};

        while (R - L > 3)
        {
            int lm = (L * 2 + R) / 3, rm = (L + 2 * R) / 3;
            if (f(lm) > f(rm))
                R = rm;
            else
                L = lm;
        }

        i64 max = 0ll;
        for (int i = L; i <= R; i++)
            max = std::max(max, f(i));
        ans.push_back(max);
    }
    int kmax = (int)ans.size() - 1;
    std::cout << kmax << '\n';
    for (int i = 1; i <= kmax; i++)
        std::cout << ans[i] << " ";
    std::cout << '\n';
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