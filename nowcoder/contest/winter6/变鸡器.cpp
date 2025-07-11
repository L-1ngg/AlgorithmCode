#include <bits/stdc++.h>
std::string s = "CHICKEN#";

void solve()
{
    int n;  std::cin >> n;
    std::string str;  std::cin >> str;

    std::vector<int> a(26, 0);

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == s[j])
        {
            j++;
            continue;
        }
        a[str[i] - 'A']++;
    }
    if (j != 7)
        std::cout << "NO\n";
    else
    {
        int sum = 0, mx = 0;
        for (auto x : a)
        {
            sum += x;
            mx = std::max(mx, x);
        }
        if (sum & 1)
            std::cout << "NO\n";
        else if (mx > sum / 2)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
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