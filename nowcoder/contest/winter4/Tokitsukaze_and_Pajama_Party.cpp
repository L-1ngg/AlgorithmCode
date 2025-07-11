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
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::string s;
    std::cin >> s;

    i64 ans = 0;
    std::vector<int> cnt(n, 0);

    if (s[0] == 'u')
        cnt[0] = 1;

    for (int i = 1; i <= n - 8; ++i) {
        cnt[i] = cnt[i - 1];
        if (s[i] == 'u')
            cnt[i]++;
        if (i >= 2 && s.substr(i, 8) == "uwawauwa")
            ans += cnt[i - 2];
    }

    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;std::cin >> t;
    while (t--)
        solve();
}