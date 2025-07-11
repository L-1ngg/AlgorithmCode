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
    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];

    int pre = 0;
    for (int i = 1; i <= n;i++)
    {
        if (a[i] && pre == 0)
        {
            int num = i - pre - 1;
            for (int j = 1; j <= num;j++)
                a[i - j] = a[i - j + 1] + 1;
            pre = i;
        }
        else if (a[i]) {
            if (a[i] - a[pre] > i - pre) {
                std::cout << "-1";
                return;
            }

            int num = i - pre - 1;
            for (int j = 1; j <= num;j++)
            {
                if (a[pre + j - 1] <= a[i])
                    a[pre + j] = a[pre + j - 1] + 1;
                else
                    a[pre + j] = a[pre + j - 1] - 1;
            }
            pre = i;
        }
        else if (i == n) {
            int num = i - pre;
            for (int j = 1; j <= num;j++)
                a[pre + j] = a[pre + j - 1] + 1;
        }
    }

    for (int i = 2; i <= n;i++)
        if (std::abs(a[i] - a[i - 1]) != 1)
        {
            std::cout << "-1";
            return;
        }

    for (int i = 1; i <= n;i++)
        std::cout << a[i] << " ";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}