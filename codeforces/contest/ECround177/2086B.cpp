#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;

void solve()
{
    int n, k;   i64 x;
    std::cin >> n >> k >> x;

    std::vector<int> a(n + 1);
    std::vector<i64> suf(n + 1);

    for (int i = 1; i <= n;i++)
        std::cin >> a[i];
    if (a[n] >= x) {
        std::cout << n * k << '\n';
        return;
    }

    int p = 0;
    suf[n] = a[n];
    for (int i = n - 1; i >= 1;i--)
    {
        suf[i] = suf[i + 1] + a[i];
        if (suf[i] >= x) { p = i;break; }
    }

    if (p)
    {
        std::cout << n * k - (n - p) << '\n';
        return;
    }
    else {
        int num = x / suf[1];
        if (num > k) {
            std::cout << 0 << '\n';
            return;
        }
        else if (num == k)
        {
            if (x % suf[1] == 0) {
                std::cout << 1 << '\n';
                return;
            }
            else {
                std::cout << 0 << '\n';
                return;
            }
        }
        else
        {
            int yu = x % suf[1];
            if (yu == 0)
            {
                std::cout << n * k - n * num + 1 << '\n';
                return;
            }
            for (int i = n;i >= 1;i--)
            {
                if (suf[i] >= yu)
                {
                    p = i;break;
                }
            }
            std::cout << n * k - n * num - (n - p) << '\n';
            return;
        }
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