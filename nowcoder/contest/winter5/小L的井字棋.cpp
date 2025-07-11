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
    int num = 0, cnt = 0;
    int a[4] = { 0 }, b[4] = { 0 };
    int x1 = 0, x2 = 0;
    std::vector<std::string> str(4);
    for (int i = 1;i <= 3; i++)
    {
        std::cin >> str[i];
        for (int j = 1; j <= 3; j++)
            if (str[i][j - 1] == 'O')
            {
                cnt++;
                a[i]--, b[j]--;
                if (i == j)
                    x1--;
                if (i + j == 4)
                    x2--;
            }
    }

    for (int i = 1; i <= 3; i++)
    {
        if (a[i] == 0)
            num++;
        if (b[i] == 0)
            num++;
    }

    if (x1 == 0)
        num++;
    if (x2 == 0)
        num++;

    if (num >= 2)
        std::cout << "Yes\n";
    else if (num == 1)
    {
        int f = 0;
        for (int i = 1; i <= 3;i++)
            if (str[i] == "GGG")
                f = 1;
        for (int i = 1; i <= 3;i++)
        {
            std::string tmp = "";
            for (int j = 1; j <= 3;j++)
                tmp += str[j][i - 1];
            if (tmp == "GGG")
                f = 1;
        }
        if (str[1].substr(0, 1) + str[2].substr(1, 1) + str[3].substr(2, 1) == "GGG")
            f = 1;
        if (str[1].substr(2, 1) + str[2].substr(1, 1) + str[3].substr(0, 1) == "GGG")
            f = 1;
        if (f)
            std::cout << "No\n";
        else
            std::cout << "Yes\n";
    }
    else
        std::cout << "No\n";
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