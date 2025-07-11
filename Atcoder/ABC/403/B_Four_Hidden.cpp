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
    std::string s, t;   std::cin >> s >> t;
    int len1 = s.length();
    int len2 = t.length();
    for (int i = 0;i <= len1 - len2;i++) {
        int j = 0;
        if (s[i] == t[j] || s[i] == '?') {
            while (j < len2) {
                if (s[i + j] == t[j] || s[i + j] == '?') j++;
                else break;
            }
            if (j == len2) {
                std::cout << "Yes";
                return;
            }
        }
    }
    std::cout << "No";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}