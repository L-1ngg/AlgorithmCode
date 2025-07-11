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
    std::string s;  std::cin >> s;
    int n = s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n;i++)
    {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    std::vector<int> cnt(n);
    for (int i = 0; i < n;i++)  cnt[i] = 1;
    for (int i = n - 1;i >= 0;i--) if (pi[i])   cnt[pi[i] - 1] += cnt[i];

    std::vector<pii> ans;
    ans.push_back({ n,1 });
    int j = pi[n - 1];
    while (j) {
        ans.push_back({ j,cnt[j - 1] });
        j = pi[j - 1];
    }
    std::cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0;i--)
        std::cout << ans[i].first << " " << ans[i].second << '\n';
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