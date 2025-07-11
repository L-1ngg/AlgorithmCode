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
    int n, k;   std::cin >> n >> k;
    std::string s;  std::cin >> s;
    std::vector<int> a(n + 1), pre(n + 1, 0);

    for (int i = 1; i < n;i++)
    {
        a[i] = std::abs(s[i] - s[i - 1]);
        pre[i] = pre[i - 1] + a[i];
    }

    i64 ans = 0;
    for (int i = 0;i <= n - k;i++)
    {
        int j = i + k - 1;
        ans += pre[j] - pre[i];
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}