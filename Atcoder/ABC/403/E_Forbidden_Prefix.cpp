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
const int N = 5e5 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int nex[N][26], sz[N], exist[N];
int cnt = 0;

void solve()
{
    int n;  std::cin >> n;
    int ans = 0;
    while (n--) {
        int op; std::cin >> op;
        std::string s;  std::cin >> s;

        int p = 0;
        if (op == 1) {
            bool ok = 1;
            for (auto& x : s) {
                int c = x - 'a';
                if (!nex[p][c]) nex[p][c] = ++cnt;
                p = nex[p][c];
                if (exist[p]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                exist[p] = 1;
                int pp = 0;
                ans -= sz[p];
                for (auto& x : s) {
                    int c = x - 'a';
                    pp = nex[pp][c];
                    sz[pp] -= sz[p];
                }
            }
        }
        else {
            bool ok = 1;
            for (auto& x : s) {
                int c = x - 'a';
                if (!nex[p][c]) nex[p][c] = ++cnt;
                p = nex[p][c];
                if (exist[p]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ans++;
                int pp = 0;
                for (auto& x : s) {
                    int c = x - 'a';
                    pp = nex[pp][c];
                    sz[pp]++;
                }
            }
        }
        std::cout << ans << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}