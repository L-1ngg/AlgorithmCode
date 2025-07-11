#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define x first 
#define y second

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
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::vector<pii> v;
    for (int i = 0;i < n;i++)
    {
        int sz = v.size();
        for (int l = i - 1;l >= 0;l--)
        {
            if (a[l] % a[i] == 0 || a[i] % a[l] == 0)
            {
                v.push_back({ l,i });
                break;
            }
        }
        for (int r = i + 1; r < n;r++)
        {
            if (a[r] % a[i] == 0 || a[i] % a[r] == 0)
            {
                v.push_back({ i,r });
                break;
            }
        }
        if (v.size() == sz || a[i] == 1)
        {
            std::cout << "-1\n";
            return;
        }
    }
    std::sort(v.begin(), v.end());
    int l = -1;
    int ans = 0;
    for (int i = 0; i < v.size();i++)
    {
        if (v[i].x == l + 1)
        {
            ans++;
            l = v[i].y;
        }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}