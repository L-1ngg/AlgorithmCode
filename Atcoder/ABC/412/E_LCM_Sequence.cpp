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
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<i64> prime;
std::vector<int> vis(MAXN, 1);
void Prime(int n) {
    vis[0] = vis[1] = 0;
    for (int i = 2; i * i <= n;i++) {
        if (vis[i]) {
            for (int j = i * i;j <= n;j += i)
                vis[j] = 0;
        }
    }
    for (int i = 2;i <= n;i++)
        if (vis[i]) prime.push_back(i);
}


void solve()
{
    i64 l, r;   std::cin >> l >> r;
    int ans = 1;
    std::vector<int> cnt(r - l + 1 + 1, 1);
    for (auto x : prime) {
        if (x > r) break;
        i64 b = x;
        while (b <= r) {
            if (b >= l + 1)
                ans++;
            b *= x;
        }

        for (i64 i = (i64)(l / x + 1) * x; i <= r;i += x) {
            cnt[i - l + 1] = 0;
        }
    }
    for (int i = 2;i <= r - l + 1;i++)
        if (cnt[i]) ans++;
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    Prime(N);
    solve();
}