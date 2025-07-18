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
    int n, idx;
    vector<vector<int>> ch;
    vector<int> pos;
    Trie(int n) {
        this->n = n;
        idx = 0;
        ch.assign(30 * (n + 1), vector<int>(2, -1));
        pos.resize(30 * (n + 1));
    }
    void insert(int x, int p) {
        int u = 0;
        for (int i = 30; ~i; i--) {
            int& v = ch[u][x >> i & 1];
            if (v == -1) v = ++idx;
            u = v;
            pos[u] = p;
        }
    }

    int query(int x, int k) {
        int c = 0;
        int mxidx = 0;
        for (int i = 30;~i;i--) {
            int b = x >> i & 1;
            int t = k >> i & 1;
            if (t == 0 && ch[c][b ^ 1] != -1)
                mxidx = std::max(mxidx, pos[ch[c][b ^ 1]]);
            c = ch[c][b ^ t];
            if (c == -1) break;
        }
        if (c != -1)
            mxidx = std::max(mxidx, pos[c]);
        return mxidx;
    }

    void clear() {
        for (int i = 0;i <= idx;i++) {
            pos[i] = 0;
            for (int j = 0;j <= 1;j++)
                ch[i][j] = -1;
        }
        idx = 0;
    }
}tr(2e5);

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    if (k == 0) {
        std::cout << "1\n";
        return;
    }
    // Trie tr()
    tr.clear();
    int ans = n + 1;
    for (int i = 1;i <= n;i++) {
        int mxidx = tr.query(a[i], k);
        if (mxidx > 0) ans = std::min(ans, i - mxidx + 1);
        tr.insert(a[i], i);
    }
    std::cout << (ans > n ? -1 : ans) << '\n';
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