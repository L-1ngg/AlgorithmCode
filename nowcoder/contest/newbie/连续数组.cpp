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
    int k;  std::cin >> k;
    std::vector<std::vector<int>> a(k);

    int f = 0;
    for (int i = 0; i < k;i++)
    {
        int j = 0;  std::cin >> j;
        a[i].resize(j);
        for (auto& x : a[i])
            std::cin >> x;

        for (int t = 1; t < j;t++)
            if (a[i][t] <= a[i][t - 1])
                f = 1;
    }
    if (f)
    {
        std::cout << "NO";
        return;
    }
    std::vector<int> tmp;
    for (int i = 0; i < k;i++)
    {
        for (auto x : a[i])
            tmp.push_back(x);
    }
    ranges::sort(tmp);
    for (int i = 1; i < tmp.size();i++)
    {
        if (tmp[i] != tmp[i - 1] + 1)
        {
            f = 1;
            break;
        }
    }
    if (f)
        std::cout << "NO";
    else std::cout << "YES";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}