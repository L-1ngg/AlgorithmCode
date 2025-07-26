#include <bits/stdc++.h>
using namespace std;
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
    int n;  std::cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> col(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> col[i];

    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    i64 ans = 0;
    int root = 0;
    int MaxTree = inf;
    vector<int> vis(n + 1), siz(n + 1);

    auto get = [&](auto self, int x, int fa, int current_n) -> void {
        siz[x] = 1;
        int val = 0;
        for (int y : adj[x]) {
            if (y == fa || vis[y]) continue;
            self(self, y, x, current_n);
            siz[x] += siz[y];
            val = max(val, siz[y]);
        }
        val = max(val, current_n - siz[x]);
        if (val < MaxTree) {
            MaxTree = val;
            root = x;
        }
        };

    auto clac = [&](int x) -> void {
        map<int, long long> all_color_freq;
        i64 all_distinct_sum = 0;
        i64 all_paths_count = 0;

        // 1. 先收集所有子树的信息
        for (int y : adj[x]) {
            if (vis[y]) continue;

            map<int, int> path_freq; // DFS过程中路径的颜色频率
            auto dfs = [&](auto self, int u, int p) -> void {
                path_freq[col[u]]++;

                // 记录一条新路径 x...u
                all_paths_count++;
                all_distinct_sum += path_freq.size();
                for (auto const& [c, f] : path_freq) {
                    all_color_freq[c]++;
                }

                for (int v_child : adj[u]) {
                    if (v_child != p && !vis[v_child]) {
                        self(self, v_child, u);
                    }
                }
                path_freq[col[u]]--;
                if (path_freq[col[u]] == 0) {
                    path_freq.erase(col[u]);
                }
                };
            path_freq[col[x]]++;
            dfs(dfs, y, x);
        }

        ans += all_paths_count * all_distinct_sum;
        i64 intersection_sum_all = 0;
        for (auto const& [c, freq] : all_color_freq) {
            intersection_sum_all += freq * (freq - 1) / 2;
        }
        ans -= intersection_sum_all;

        for (int y : adj[x]) {
            if (vis[y]) continue;

            map<int, i64> sub_color_freq;
            i64 sub_distinct_sum = 0;
            i64 sub_paths_count = 0;
            map<int, int> path_freq;

            auto dfs = [&](auto self, int u, int p) -> void {
                path_freq[col[u]]++;
                sub_paths_count++;
                sub_distinct_sum += path_freq.size();
                for (auto const& [c, f] : path_freq) {
                    sub_color_freq[c]++;
                }
                for (int v_child : adj[u]) {
                    if (v_child != p && !vis[v_child]) {
                        self(self, v_child, u);
                    }
                }
                path_freq[col[u]]--;
                if (path_freq[col[u]] == 0) {
                    path_freq.erase(col[u]);
                }
                };
            path_freq[col[x]]++;
            dfs(dfs, y, x);

            ans -= sub_paths_count * sub_distinct_sum;
            i64 intersection_sum_sub = 0;
            for (auto const& [c, freq] : sub_color_freq) {
                intersection_sum_sub += freq * (freq - 1) / 2;
            }
            ans += intersection_sum_sub;
        }


        ans += all_distinct_sum;
        };

    auto dfz = [&](auto self, int x, int fa) -> void {
        vis[x] = 1;
        clac(x);
        for (int y : adj[x]) {
            if (y == fa || vis[y]) continue;
            MaxTree = 1e18;
            root = 0; // 重置 root
            get(get, y, x, siz[y]);
            self(self, root, x);
        }
        };

    get(get, 1, 0, n);
    dfz(dfz, root, 0);
    cout << ans << endl;
}

signed main()
{
    // freopen("tournament.in", "r", stdin);
    // freopen("tournament.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}