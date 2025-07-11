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
const int N = 1e6 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

struct node {
    int son[26];
    int ans = 0;
    int fail;
};

node tr[N];
int tot = 0;
void solve()
{
    int n;  std::cin >> n;
    for (int i = 1; i <= n;i++) {
        std::string s;  std::cin >> s;
        int u = 0;
        for (auto x : s)
        {
            int c = x - 'a';
            if (!tr[u].son[c]) tr[u].son[c] = ++tot;
            u = tr[u].son[c];
        }
        tr[u].ans++;
    }

    std::queue<int> q;
    for (int i = 0; i < 26;i++) if (tr[0].son[i]) q.push(tr[0].son[i]);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 26;i++) {
            if (tr[u].son[i]) {
                tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                q.push(tr[u].son[i]);
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];
        }
    }

    std::string t;  std::cin >> t;
    int u = 0, res = 0;
    for (auto x : t) {
        u = tr[u].son[x - 'a'];
        for (int j = u; j && tr[j].ans != -1;j = tr[j].fail)
            res += tr[j].ans, tr[j].ans = -1;
    }
    std::cout << res;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}