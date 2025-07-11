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
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + 1), r_(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];
    for (int i = 1; i <= n;i++)
        std::cin >> r_[i];

    std::map<int, int> mp;

    auto check = [&](int i, int j) {
        i64 l = 0, r = r_[i];
        i64 x = std::abs(j - a[i]);
        while (l <= r)
        {
            i64 mid = (l + r) >> 1;
            if (x * x + mid * mid <= (i64)r_[i] * r_[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return (int)r;
        };

    for (int i = 1; i <= n;i++)
    {
        int L = a[i] - r_[i], R = a[i] + r_[i];
        for (int j = L; j <= R;j++)
            mp[j] = std::max(mp[j], check(i, j));
    }

    i64 sum = 0;
    for (auto it = mp.begin();it != mp.end();it++)
        sum += (it->second * 2ll + 1);
    std::cout << sum << '\n';
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