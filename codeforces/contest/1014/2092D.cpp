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
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    std::vector<int> a(n);
    int cnt[3]{};


    if (std::count(s.begin(), s.end(), s[0]) == n)
    {
        std::cout << "-1\n";
        return;
    }
    for (int i = 0; i < n;i++)
    {
        a[i] = (s[i] == 'L' ? 0 : (s[i] == 'I' ? 1 : 2));
        cnt[a[i]]++;
    }

    std::vector<int> ans;
    int mn = *std::min_element(cnt, cnt + 3);
    for (int i = 0;i < 3;i++)
    {
        if (cnt[i] == mn)    continue;

        int p = 1;
        while ((a[p - 1] == i) == (a[p] == i))
            p++;
        // std::cout << p << "e" << '\n';
        while (cnt[i] > mn)
        {
            if (a[p] == i)
            {
                int y = a[p - 1];
                a.insert(a.begin() + p, 3 - i - y);
                ans.push_back(p);
                a.insert(a.begin() + p + 1, y);
                ans.push_back(p + 1);
                p += 2;
            }
            else {
                int y = a[p];
                a.insert(a.begin() + p, 3 - i - y);
                ans.push_back(p);
                a.insert(a.begin() + p, y);
                ans.push_back(p);
            }
            cnt[i]--;
        }
    }

    std::cout << ans.size() << '\n';
    for (auto x : ans)
        std::cout << x << '\n';
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