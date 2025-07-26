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
const int MAXN = 7e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 500009;

void solve() {
    int t;  std::cin >> t;
    std::vector<pii> q(t + 1);
    for (int i = 1;i <= t;i++) {
        std::cin >> q[i].first;
        q[i].second = i;
    }
    std::sort(q.begin() + 1, q.end());

    std::vector<int> cnt(MAXN + 1, 0);
    for (int i = 1;i <= MAXN;i++)
    {
        cnt[i]++;
        int j = i;
        while ((j += i) <= MAXN) cnt[j]++;
    }
    std::vector<int> ccnt(MAXN + 1, 0);
    std::vector<i64> ans(t + 1);

    i64 res = 1;
    for (int i = 1, j = 1;i <= MAXN && j <= t;i++)
    {
        res *= ++ccnt[cnt[i]];
        res %= mod;
        if (res == 0) break;
        // if (q[j].first == i) ans[q[j].second];
        while (j <= t && q[j].first == i) ans[q[j].second] = res, j++;
    }

    // i64 res = 1;
    // for (int i = 1, j = 1;i <= t;i++)
    // {
    //     while (j < q[i].first) {
    //         res *= ++ccnt[cnt[++j]];
    //         res %= mod;
    //         if (!res) break;
    //     }
    //     ans[q[i].second] = res;
    // }
    for (int i = 1;i <= t;i++)
        std::cout << ans[i] << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}