#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e4 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<int> p;
int isp[N];

void get(int n) {
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= n;i++)  isp[i] = 1;
    for (int i = 2; i <= n;i++)
    {
        if (isp[i])
        {
            p.push_back(i);
            if (i * i > n) continue;
            for (int j = i * i; j <= n;j += i)
                isp[j] = 0;
        }
    }
}

bool check(int x)
{
    int base = 2;
    while (1)
    {
        if (base * base > x)    return 0;
        if ((x % (base * base)) == 0)   return 1;
        ++base;
    }
}

void solve()
{
    get(N);
    int n;  std::cin >> n;
    int mn = inf, cnt = 0;

    for (int i = 0; i < p.size();i++)
    {
        if (p[i] >= n) break;

        if (check(n - p[i]))
        {
            cnt++;
            mn = std::min(mn, std::abs(p[i] - (n - p[i])));
        }
    }
    std::cout << cnt << '\n' << mn;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}