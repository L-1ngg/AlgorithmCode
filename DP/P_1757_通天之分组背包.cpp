#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> m >> n;
    std::map<int, std::vector<pii>> mp;
    for (int i = 1;i <= n;i++)
    {
        int w, v, k;    std::cin >> w >> v >> k;
        mp[k].push_back({ w,v });
    }
    std::vector<int> f(m + 1, 0);
    for (auto it = mp.begin();it != mp.end();it++)
        for (int i = m;i >= 0;i--)
            for (auto [w, v] : it->second) {
                if (i < w) continue;
                f[i] = std::max(f[i], f[i - w] + v);
            }
    std::cout << f[m];
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