#include <bits/stdc++.h>
int popcount(int x)
{
    int res = 0;
    while (x)
    {
        res++;
        x &= (x - 1);
    }
    return res;
}
void solve()
{
    int n, m;   std::cin >> n >> m;

    std::vector<int> a(n + 1), st;
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    int ans = 0;
    for (int i = 0; i < 1 << n;i++) {
        if (__builtin_popcount(i) != n - m) continue;
        std::bitset<2005> b;
        b[0] = 1;
        for (int j = 0; j < n;j++)
            if (i >> j & 1)
                b |= b << a[j + 1];
        ans = std::max(ans, (int)b.count());
    }
    std::cout << ans - 1;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}