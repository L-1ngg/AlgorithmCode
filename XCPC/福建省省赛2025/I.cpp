#include <bits/stdc++.h>
using pii = std::pair<int, int>;
void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = "  " + s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 2;i <= n - 1;i++)
        (s[i] == '0' ? cnt0++ : cnt1++);
    if (cnt0 == 0 || (cnt0 == 1 && s[n - 1] == '1'))
    {
        std::cout << "-1\n";
        return;
    }
    std::vector<pii> ans;
    int pre = 1;
    for (int i = 2;i <= n - 1;i++)
        if (s[i] == '1')
        {
            ans.push_back({ pre,i });
            pre = i;
        }
    ans.push_back({ pre, n });
    if (cnt0 == 1) ans.push_back({ 1,n - 1 });
    else {
        pre = 1;
        for (int i = 2;i <= n - 1;i++)
            if (s[i] == '0')
            {
                ans.push_back({ pre,i });
                pre = i;
            }
        ans.push_back({ pre,1 });
    }
    std::cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        std::cout << u << " " << v << '\n';
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