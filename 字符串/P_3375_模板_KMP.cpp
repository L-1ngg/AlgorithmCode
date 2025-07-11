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
const int MAXN = 1e5 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;
const int base = 233;


void solve()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    std::string cur = s2 + "#" + s1;
    // std::cout << cur << '\n';
    std::vector<int> pi1(len1 + 1 + len2);
    for (int i = 1; i < len1 + 1 + len2;i++) {
        int j = pi1[i - 1];
        while (j && cur[i] != cur[j]) j = pi1[j - 1];
        if (cur[i] == cur[j]) j++;
        pi1[i] = j;
        if (j == len2)   std::cout << i - 2 * len2 + 1 << '\n';
    }
    std::vector<int> pi2(len2);
    std::cout << "0 ";
    for (int i = 1; i < len2;i++) {
        int j = pi2[i - 1];
        while (j && s2[i] != s2[j]) j = pi2[j - 1];
        if (s2[i] == s2[j]) j++;
        pi2[i] = j;
        std::cout << j << " \n"[i == len2 - 1];
    }
}

//hash
// u64 p[MAXN];
// u64 s[MAXN], t[MAXN];

// u64 subhash(u64* hash, int l, int r) {
//     return hash[r] - hash[l - 1] * p[r - l + 1];
// }

// void solve() {
//     std::string S, T;   std::cin >> S >> T;
//     s[0] = S[0], t[0] = T[0];
//     int len1 = S.length(), len2 = T.length();
//     for (int i = 1; i < len1;i++)
//         s[i] = s[i - 1] * base + S[i];
//     for (int i = 1; i < len2;i++)
//         t[i] = t[i - 1] * base + T[i];

//     for (int i = 0; i + len2 <= len1;i++) {
//         if (subhash(s, i, i + len2 - 1) == t[len2 - 1])
//             std::cout << i + 1 << '\n';
//     }
// }

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // p[0] = 1;
    // for (int i = 1;i <= MAXN - 10;i++)  p[i] = p[i - 1] * base;
    solve();
}