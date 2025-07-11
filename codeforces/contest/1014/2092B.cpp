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
    std::string a, b;   std::cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n;i++)
    {
        if (a[i] == '1' && (i & 1))
            cnt1++;
        else if (a[i] == '1' && !(i & 1))
            cnt2++;
    }

    int n1 = 0, n2 = 0;
    for (int i = 0; i < n;i++)
    {
        if (b[i] == '0' && (i & 1))
            n2++;
        else if (b[i] == '0' && !(i & 1))
            n1++;
    }
    if (n2 >= cnt2 && n1 >= cnt1)
        std::cout << "YES\n";
    else std::cout << "NO\n";
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