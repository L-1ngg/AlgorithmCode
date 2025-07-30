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
    s = " " + s;
    int i = 1, j = n;
    while (i <= j) {
        if (s[i] == s[j]) i++, j--;
        else break;
    }
    if (i > j) {
        std::cout << "0\n";
        return;
    }

    int l = n / 2, r = l + 1;
    while (1)
    {
        if (s[l] != s[r]) break;
        l--, r++;
    }
    std::vector<int> cnt(26, 0);
    for (int t = i;t <= l;t++) cnt[s[t] - 'a']++;
    for (int t = r;t <= j;t++) cnt[s[t] - 'a']--;
    int f = 1;
    for (int i = 0;i < 26;i++)  if (cnt[i]) f = 0;
    if (f) {
        std::cout << l - i + 1 << '\n';
        return;
    }

    int ans = inf, res = 0;
    cnt.assign(26, 0);
    l = i, r = j;
    for (int i = l;i <= r;i++)
        cnt[s[i] - 'a']++;

    std::vector<int> tmp(26, 0);
    for (i = l;i <= r;i++)
    {
        tmp[s[i] - 'a']++;
        if (tmp[s[i] - 'a'] > cnt[s[i] - 'a'] / 2) break;
    }
    ans = std::min(ans, r - i + 1);

    tmp.assign(26, 0);
    for (i = r;i >= l;i--)
    {
        tmp[s[i] - 'a']++;
        if (tmp[s[i] - 'a'] > cnt[s[i] - 'a'] / 2) break;
    }
    ans = std::min(ans, i - l + 1);
    std::cout << ans << '\n';
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