
#include <bits/stdc++.h>
void solve()
{
    int x, n, m;  std::cin >> x >> n >> m;

    auto calc1 = [](int x, int n, int m)
        {
            if (m >= 30 || n >= 30)    return 0;
            while (x && (n || m))
            {
                if (x % 2 == 0 && m)  x /= 2, m--;
                else if (x % 2 == 1 && n > 1) x /= 2, n--;
                else if (m) x = x / 2 + (x % 2), m--;
                else    x = x / 2, n--;
            }
            return x;
        };
    auto calc2 = [](int x, int n, int m)
        {
            if (n >= 30)    return 0;
            while ((x && (n || m)))
            {
                if (n == 0 && m > std::__lg(x))    return 1;

                if (x % 2 == 0 && n)  x /= 2, n--;
                else if (x % 2 == 1 && m > 1)  x = x / 2 + (x % 2), m--;
                else if (n) x = x / 2, n--;
                else    x = x / 2 + (x % 2), m--;
            }
            return x;
        };

    std::cout << calc1(x, n, m) << ' ' << calc2(x, n, m) << '\n';
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