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
    int k;  std::cin >> k;
    i64 n;  std::cin >> n;

    i64 ans = 0;
    for (int t = 1;t <= 1e6;t++) {
        std::string a = std::to_string(t);
        std::string b = a;
        reverse(a.begin(), a.end());
        b += a;
        i64 now = std::stoll(b);
        if (now > n) continue;
        i64 res = now;

        std::string tmp = "";
        while (now) {
            tmp += '0' + now % k;
            now /= k;
        }
        int len = tmp.size();
        int f = 0;
        for (int i = 0;i < len / 2;i++)
        {
            if (tmp[i] != tmp[len - 1 - i])
            {
                f = 1;
                break;
            }
        }
        if (f) continue;
        ans += res;
    }
    for (int t = 1;t <= 1e6;t++) {
        std::string a = std::to_string(t);
        std::string b = a;
        reverse(a.begin(), a.end());
        b.pop_back();
        b += a;
        i64 now = std::stoll(b);
        if (now > n) continue;
        i64 res = now;

        std::string tmp = "";
        while (now) {
            tmp += '0' + now % k;
            now /= k;
        }
        int len = tmp.size();
        int f = 0;
        for (int i = 0;i < len / 2;i++)
        {
            if (tmp[i] != tmp[len - 1 - i])
            {
                f = 1;
                break;
            }
        }
        if (f) continue;
        ans += res;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}