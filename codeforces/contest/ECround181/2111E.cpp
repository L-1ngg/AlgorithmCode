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
    int n, q;   std::cin >> n >> q;
    std::string s;  std::cin >> s;
    std::vector<int> cnt(6, 0);
    for (int i = 0;i < q;i++) {
        char x, y;  std::cin >> x >> y;
        if (x == 'b' && y == 'a')   cnt[0]++;
        if (x == 'c' && y == 'a')   cnt[1]++;
        if (x == 'b' && y == 'c')   cnt[2]++;
        if (x == 'c' && y == 'a')   cnt[3] = std::min(cnt[2], ++cnt[3]);
        if (x == 'c' && y == 'b')   cnt[4]++;
        if (x == 'b' && y == 'a')   cnt[5] = std::min(cnt[4], ++cnt[5]);
    }
    for (int i = 0;i < n;i++) {
        if (s[i] == 'b') {
            if (cnt[0]) {
                s[i] = 'a', cnt[0]--;
                cnt[5] = std::min(cnt[0], cnt[5]);
            }
            else if (cnt[3]) {
                s[i] = 'a';
                cnt[1]--;
                cnt[2]--;
                cnt[3]--;
            }
        }
        if (s[i] == 'c') {
            if (cnt[1]) {
                s[i] = 'a', cnt[1]--;
                cnt[3] = std::min(cnt[1], cnt[3]);
            }
            else if (cnt[5]) {
                s[i] = 'a';
                cnt[4]--;
                cnt[5]--;
                cnt[0]--;
            }
            else if (cnt[4]) {
                s[i] = 'b';
                cnt[4]--;
            }
        }
    }
    std::cout << s << '\n';
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