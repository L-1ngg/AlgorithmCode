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

struct node {
    int a[55], cnt = inf, no;
};

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> need(m + 1);
    std::vector<node> arr(55);
    for (int i = 1; i <= m;i++)
        std::cin >> need[i];

    for (int i = 1;i <= n;i++)
    {
        arr[i].no = i;
        for (int j = 1; j <= m;j++)
        {
            std::cin >> arr[i].a[j];
            arr[i].cnt = std::min(arr[i].cnt, arr[i].a[j] / need[j]);
        }
    }

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
            arr[i].a[j] -= arr[i].cnt * need[j];
    }

    for (int i = 1; i <= m;i++)
    {
        auto cmp = [&](node& n1, node& n2)
            {
                if (n1.a[i] == n2.a[i])
                {
                    if (n1.cnt == n2.cnt)
                        return n1.no < n2.no;
                    return n1.cnt > n2.cnt;
                }
                return n1.a[i] < n2.a[i];
            };

        std::sort(arr.begin() + 1, arr.begin() + 1 + n, cmp);
        for (int j = 1; j <= n;j++)
            std::cout << arr[j].no << ' ';
        std::cout << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}