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
    int n;  std::cin >> n;
    std::string str;  std::cin >> str;

    auto op = [&](std::string s)-> int {
        int len = s.size();
        int mx = 0;
        std::vector<int> pi(len);
        for (int i = 1; i < len;i++) {
            int j = pi[i - 1];
            while (j && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
            mx = std::max(mx, j);
        }
        return mx;
        };

    i64 ans = 1;
    for (int i = 2;i <= n;i++) {
        std::string tmp = str.substr(0, i);
        reverse(tmp.begin(), tmp.end());
        int cnt = op(tmp);
        ans += i - cnt;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}