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
    int n, m, q;    std::cin >> n >> m >> q;
    std::vector<pii> ans;
    ans.push_back({ m,m });
    while (q--) {
        int p;  std::cin >> p;
        std::vector<pii> tmp;
        for (auto [l, r] : ans) {
            if (p < l) tmp.push_back({ l - 1,r });
            else if (p > r)  tmp.push_back({ l,r + 1 });
            else {
                tmp.push_back({ 1,1 });
                tmp.push_back({ n,n });
                if (l != r)
                    tmp.push_back({ l,r });
            }
        }
        ranges::sort(tmp);
        std::vector<pii> merge;
        for (auto [l, r] : tmp) {
            if (merge.empty() || merge.back().second < l)
                merge.push_back({ l,r });
            else merge.back().second = r;
        }
        ans = merge;
        int res = 0;
        for (auto [l, r] : ans) {
            res += r - l + 1;
        }
        std::cout << res << " ";
    }
    std::cout << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}