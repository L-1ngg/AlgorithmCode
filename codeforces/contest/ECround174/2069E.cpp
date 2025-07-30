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
    int c0, c1, c01, c10;   std::cin >> c0 >> c1 >> c01 >> c10;
    std::vector<std::vector<int>> a;
    int lst = 0;
    for (int i = 0;i < s.length();i++)
    {
        if (i && s[i] == s[i - 1]) {
            std::vector<int> b;
            for (int j = lst;j <= i - 1;j++)
                b.push_back(s[j] - 'A');
            a.push_back(b);
            lst = i;
        }
    }
    std::vector<int> b;
    for (int j = lst;j < s.length();j++)
        b.push_back(s[j] - 'A');
    a.push_back(b);

    auto check = [&]() ->bool {
        int any = 0;
        std::vector<int> a01, a10;
        for (auto x : a) {
            if (x.size() == 1) {
                if (x[0] == 0) c0--;
                else c1--;
            }
            else if (x.size() == 2) {
                if (x[0] == 0) {
                    if (c01)   c01--;
                    else  c0--, c1--;
                }
                if (x[0] == 1) {
                    if (c10)   c10--;
                    else  c0--, c1--;
                }
            }
            else {
                if (x.size() & 1) {
                    if (x[0] == 0) c0--, any += x.size() / 2;
                    if (x[0] == 1) c1--, any += x.size() / 2;
                }
                else {
                    if (x[0] == 0) a01.push_back(x.size() / 2);
                    if (x[0] == 1) a10.push_back(x.size() / 2);
                }
            }
            if (c0 < 0 || c1 < 0) return 0;
        }

        ranges::sort(a01);
        ranges::sort(a10);
        for (auto x : a01) {
            if (c01 >= x) c01 -= x;
            else c0--, c1--, any += x - 1;
            if (c0 < 0 || c1 < 0) return 0;
        }
        for (auto x : a10) {
            if (c10 >= x) c10 -= x;
            else c0--, c1--, any += x - 1;
            if (c0 < 0 || c1 < 0) return 0;
        }
        return any <= c01 + c10 + std::min(c0, c1);
        };
    std::cout << (check() ? "YES" : "NO") << '\n';
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