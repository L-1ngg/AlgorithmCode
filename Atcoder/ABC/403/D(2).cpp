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

int f[N][2];
std::vector<int> b[N];
void solve()
{
    int n, d;   std::cin >> n >> d;
    std::vector<int> a(n);
    for (auto& x : a)   std::cin >> x;
    if (d == 0) {
        ranges::sort(a);
        std::cout << a.end() - std::unique(a.begin(), a.end());
        return;
    }

    for (auto x : a) b[x % d].push_back(x / d);

    int ans = 0;
    for (int i = 0; i < d;i++) {
        if (b[i].size() > 1) {
            ranges::sort(b[i]);
            f[0][0] = 1; //shan
            f[0][1] = 0; //liu

            int j;
            for (j = 1; j < b[i].size();j++) {
                if (b[i][j] == b[i][j - 1])
                {
                    f[j][1] = f[j - 1][1];
                    f[j][0] = f[j - 1][0] + 1;
                }
                else if (b[i][j] == b[i][j - 1] + 1) {
                    f[j][0] = std::min(f[j - 1][0], f[j - 1][1]) + 1;
                    f[j][1] = f[j - 1][0];
                }
                else {
                    f[j][1] = std::min(f[j - 1][0], f[j - 1][1]);
                    f[j][0] = std::min(f[j - 1][0], f[j - 1][1]) + 1;
                }
            }
            ans += std::min(f[j - 1][0], f[j - 1][1]);
        }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}