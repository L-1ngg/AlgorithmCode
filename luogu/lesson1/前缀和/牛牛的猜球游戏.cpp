#include <bits/stdc++.h>
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(10));
    std::iota(a[0].begin(), a[0].end(), 0);

    for (int i = 1; i <= n;i++)
    {
        int l, r;   std::cin >> l >> r;
        a[i] = a[i - 1];
        std::swap(a[i][l], a[i][r]);
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r;   std::cin >> l >> r;
        std::vector<int> ni(10);
        for (int j = 0; j < 10; j++)
            ni[a[l - 1][j]] = j;

        std::vector<int> ans(10);
        for (int j = 0; j < 10;j++)
            ans[j] = ni[a[r][j]];
        for (auto x : ans)
            std::cout << x << ' ';
        std::cout << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}