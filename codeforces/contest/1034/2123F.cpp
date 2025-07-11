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
const int N = 1e5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<int> pri;
std::vector<int> v(N + 1, 1);

void prime(int n) {
    for (int i = 2;i <= n;i++) {
        if (v[i]) pri.push_back(i);
        for (auto x : pri)
        {
            if (x * i > n) break;
            v[x * i] = 0;
            if (i % x == 0) break;
        }
    }
}

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> ans(n + 1, 0);
    ans[1] = 1;
    for (auto x : pri) {
        if (x > n) continue;
        int lst = 0;
        for (int i = x;i <= n;i += x)
        {
            if (ans[i]) continue;
            ans[i] = lst;
            lst = i;
        }
        ans[x] = lst;
    }
    for (int i = 1;i <= n;i++)
        std::cout << ans[i] << " \n"[i == n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    prime(N);
    std::reverse(pri.begin(), pri.end());
    int t;
    std::cin >> t;
    while (t--)
        solve();
}