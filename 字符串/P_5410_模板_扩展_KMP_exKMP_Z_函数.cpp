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

std::vector<int> Z1(std::string s) {
    int n = s.size();
    std::vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0;i < n;i++) {
        if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
        else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

std::vector<int> Z2(std::vector<int>& a, std::string t, std::string s) {
    int n = t.size();
    int len = s.size();
    std::vector<int> z(n);
    while (s[z[0]] == t[z[0]]) ++z[0];
    for (int i = 1, l = 0, r = 0;i < n;i++) {
        if (i <= r && a[i - l] < r - i + 1) z[i] = a[i - l];
        else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && z[i] < len && s[z[i]] == t[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

void solve()
{
    std::string t;  std::cin >> t;
    std::string s;  std::cin >> s;

    std::vector<int> a = Z1(s);
    i64 res1 = 0;
    for (int i = 0;i < a.size();i++) {
        res1 ^= 1ll * (i + 1) * (a[i] + 1);
    }

    std::vector<int> b = Z2(a, t, s);
    i64 res2 = 0;
    for (int i = 0;i < b.size();i++) {
        res2 ^= 1ll * (i + 1) * (b[i] + 1);
    }

    std::cout << res1 << '\n' << res2;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}