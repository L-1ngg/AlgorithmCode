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

struct Trie {
    int ch[N][63], cnt[N], idx = 0;
    map<int, int> mp;
    void init() {
        i64 id = 0;
        for (int i = 1;i <= 10;i++)
            mp[i] = ++id;
    }
    void insert(std::vector<int> s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = mp[s[i]];
            if (!ch[u][v]) ch[u][v] = ++idx;
            u = ch[u][v];
            cnt[u]++;
        }
    }
    i64 query(std::vector<int> s) {
        int u = 0, mx = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = mp[s[i]];
            if (!ch[u][v]) break;
            u = ch[u][v];
            mx = i + 1;
        }
        return mx;
    }
    void Clear() {
        for (int i = 0; i <= idx; i++) {
            cnt[i] = 0;
            for (int j = 0; j <= 62; j++) {
                ch[i][j] = 0;
            }
        }
        idx = 0;
    }
}trie;

void solve()
{
    int n, m;   std::cin >> n >> m;
    trie.init();
    std::vector a(n, std::vector<int>(m));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            std::cin >> a[i][j];

    auto getinv = [&](std::vector<int> p) {
        std::vector<int> inv(m);
        for (int i = 0;i < m;i++)
        {
            int v = p[i];
            inv[v - 1] = i + 1;
        }
        return inv;
        };

    for (int i = 0;i < n;i++) {
        auto inv = getinv(a[i]);
        trie.insert(inv);
    }
    auto inv = getinv(a[0]);
    for (int i = 0;i < m;i++)
        std::cout << inv[i] << " \n"[i == m - 1];
    for (int i = 0;i < n;i++)
    {
        int res = trie.query(a[i]);
        std::cout << res << " \n"[i == n - 1];
    }
    trie.Clear();
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