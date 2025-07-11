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
    char c[2];
    int a[2];
};

void solve()
{
    int n;  std::cin >> n;
    std::vector<node> arr(n + 1);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j <= 1; j++)
            std::cin >> arr[i].c[j] >> arr[i].a[j];
    }

    std::vector<int> op(n + 2, 0);
    for (int i = n;i >= 1; i--)
    {
        if (arr[i].c[0] == '+' && arr[i].c[1] == '+')
            op[i] = op[i + 1];
        else if (arr[i].c[0] == '+' && arr[i].c[1] == 'x')
            op[i] = 1;
        else if (arr[i].c[0] == 'x' && arr[i].c[1] == '+')
            op[i] = 0;
        else if (arr[i].a[0] == arr[i].a[1])
            op[i] = op[i + 1];
        else
            op[i] = (arr[i].a[0] > arr[i].a[1] ? 0 : 1);
    }

    i64 a[2] = { 1,1 };
    for (int i = 1; i <= n;i++)
    {
        i64 sum = 0;
        for (int j = 0; j <= 1;j++) {
            if (arr[i].c[j] == '+')
                sum += arr[i].a[j];
            else sum += a[j] * (arr[i].a[j] - 1);
        }
        a[op[i + 1]] += sum;
    }
    std::cout << a[0] + a[1] << '\n';
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