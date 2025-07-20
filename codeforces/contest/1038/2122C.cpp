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

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<pii> X(n + 1), Y(n + 1);
    for (int i = 1;i <= n;i++)
    {
        std::cin >> X[i].x >> Y[i].x;
        X[i].y = Y[i].y = i;
    }
    std::sort(X.begin() + 1, X.end());
    std::sort(Y.begin() + 1, Y.end());

    std::vector<pii> res(n + 1);
    for (int i = 1;i <= n;i++) {
        res[X[i].y].x = (i <= n / 2);
        res[Y[i].y].y = (i <= n / 2);
    }
    std::vector<int> ans[4];
    for (int i = 1;i <= n;i++)
        ans[res[i].x * 2 + res[i].y].push_back(i);
    for (int i = 0;i < ans[1].size();i++)
        std::cout << ans[1][i] << " " << ans[2][i] << '\n';
    for (int i = 0;i < ans[0].size();i++)
        std::cout << ans[0][i] << " " << ans[3][i] << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}