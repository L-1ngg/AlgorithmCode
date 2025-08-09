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
const int N = 1e7;
const int MAXN = 1e7 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

std::vector<int> sg(MAXN, 0);
void solve()
{
    int n;  std::cin >> n;
    int f = 0;
    while (n--) {
        int x;  std::cin >> x;
        f ^= sg[x];
    }
    std::cout << (f ? "Alice" : "Bob");
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    auto init = [&]() {
        sg[0] = 0, sg[1] = 1;
        int r = 2;
        for (int i = 3;i <= N;i += 2) {
            if (sg[i] == 0) sg[i] = r, r++;
            else continue;

            for (int j = 3 * i;j <= N;j += 2 * i)
                if (!sg[j]) sg[j] = sg[i];
        }
        };
    init();
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}