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

/*
9xx
8xx



*/
int a[10];
int f[10][10];

// void solve()
// {
//     int len;
//     auto dfs = [&](auto&& self, bool limit, bool same, bool lead0, int pos, int x) ->int {
//         if (!pos) return 1;
//         if (!limit && !same && ~f[pos][x]) return f[pos][x];

//         int res = 0;
//         int up = limit ? a[pos] : 9;
//         for (int i = 0;i <= up;i++) {
//             if (pos == len)
//                 res += self(self, limit && i == up, 1, lead0 && i == 0, pos - 1, i);
//             else res += self(self, limit && i == up, same && i == x, lead0 && i == 0, pos - 1, i);
//         }
//         if (!limit && !same) f[pos][x] = res;
//         return res;
//         };

//     auto op = [&](int x) {
//         len = 0;
//         while (x) {
//             a[++len] = x % 10;
//             x /= 10;
//         }
//         return dfs(dfs, 1, 1, 1, len, 0);
//         };

//     int n;  std::cin >> n;
//     std::cout << op(n) << '\n';
// }

void solve() {
    int n;  std::cin >> n;
    std::set<std::string> st;
    int sz = 0;
    for (int i = 1; i <= n;i++) {
        std::string s = std::to_string(i) + std::to_string(i + 1);
        std::sort(s.begin(), s.end());
        st.insert(s);

    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(f, -1, sizeof f);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}