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


std::vector<int> kmp(std::string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    f[0] = n;
    for (int i = 1, j = 0;i < n;i++) {
        while (j && s[i] != s[j])
            j = f[j];
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::string s, t; std::cin >> s >> t;
    std::string tmp = t + "#" + s;
    std::vector<int> f = kmp(tmp);
    std::vector<int> pre(n + 1, 0);
    for (int i = m;i <= n;i++) {
        if (f[i + m + 1] == m) {
            pre[i - m + 1] = 1;
        }
    }
    for (int i = 1; i <= n;i++) pre[i] += pre[i - 1];
    for (int i = 1; i <= n;i++) pre[i] += pre[i - 1];

    s = "#" + s;
    std::vector<int> d1(n + 1);
    for (int i = 0, j = 0;i <= n;i++) {
        if (2 * j - i >= 0 && i < j + d1[j])
            d1[i] = std::min(d1[2 * j - i], j + d1[j] - i);
        while (i - d1[i] >= 0 && i + d1[i] <= n && s[i - d1[i]] == s[i + d1[i]])
            d1[i]++;
        if (i + d1[i] > j + d1[j])
            j = i;
    }

    u32 ans = 0;
    for (int i = 1;i <= n;i++) {
        if (d1[i] * 2 - 1 < m) continue;
        int l = i - d1[i] + 1, r = i + d1[i] - 1;
        l--, r = r - m + 1;
        int mid = (l + r) >> 1;
        ans += (pre[r] - pre[mid] - pre[((l + r) & 1) ? mid : mid - 1] + (l == 0 ? 0 : pre[l - 1]));
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}