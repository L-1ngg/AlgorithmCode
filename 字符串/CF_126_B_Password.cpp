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

std::vector<int> a(1);
std::vector<int> kmp(std::string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0;i < n;i++) {
        while (j && s[i] != s[j])   j = f[j];
        j += (s[i] == s[j]);
        f[i + 1] = j;
        if (i != n - 1 && j > a.back()) a.push_back(j);
    }
    return f;
}

void solve()
{
    std::string s;  std::cin >> s;
    std::vector<int> b = kmp(s);
    int j = b[s.size()];
    while (j) {
        if (*std::lower_bound(a.begin(), a.end(), j) == j)
        {
            std::cout << s.substr(0, j);
            return;
        }
        j = b[j];
    }
    std::cout << "Just a legend";
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