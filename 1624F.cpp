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
const int inf = (1 << 31) - 1;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int ask(int x) {
    std::cout << "+ " << x << std::endl;
    int y;  std::cin >> y;
    return y;
}

void solve()
{
    int n;  std::cin >> n;
    int base = ask(n - 1);
    int l = 1, r = n - 1;

    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (ask(mid) == base) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    std::cout << "! " << base * n - ans << std::endl;
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