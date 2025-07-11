//aaabbbccc
//A33,A24
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
    std::vector <pii> a(26, { 0,0 });
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    for (int i = 0;i < n;i++) {
        a[s[i] - 'a'].first++;
        a[s[i] - 'a'].second = i;
    }
    ranges::sort(a);
    for (int i = 0;i < 26;i++) {
        if (a[i].first)
        {
            s[a[i].second] = s[a[25].second];
            break;
        }
    }

    std::cout << s << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}