#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 2e3 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int f[N], g[N];
void solve()
{
    int n, V; std::cin >> n >> V;
    std::vector<int> s(n + 1), v(n + 1), w(n + 1);
    for (int i = 1; i <= n;i++)
        std::cin >> v[i] >> w[i] >> s[i];

    int q[N];
    for (int k = 1; k <= n;k++) {
        memcpy(g, f, sizeof f);
        for (int i = 0;i < v[k];i++) {
            int h = 0, t = -1;
            for (int j = i;j <= V;j += v[k])
            {
                if (h <= t && q[h] < j - s[k] * v[k]) h++;
                if (h <= t) f[j] = std::max(g[j], g[q[h]] + (j - q[h]) / v[k] * w[k]);
                while (h <= t && g[j] >= g[q[t]] + (j - q[t]) / v[k] * w[k]) t--;
                q[++t] = j;
            }
        }
    }

    std::cout << f[V];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}