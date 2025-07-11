#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

struct node {
    int son[26];
    int fail;
    int idx;
    int cnt;
    int du;
};
void solve()
{
    int n;  std::cin >> n;
    std::vector<node> tr(1);
    std::vector<int> to(n + 1);
    int pidx = 0;
    for (int i = 1; i <= n;i++) {
        std::string s;  std::cin >> s;
        int u = 0;
        for (auto& x : s) {
            int c = x - 'a';
            if (!tr[u].son[c]) {
                tr[u].son[c] = tr.size();
                tr.emplace_back();
            }
            u = tr[u].son[c];
        }
        if (!tr[u].idx) tr[u].idx = ++pidx;
        to[i] = tr[u].idx;
    }
    std::queue<int> q;
    for (int i = 0;i < 26;i++) if (tr[0].son[i]) q.push(tr[0].son[i]);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0;i < 26;i++) {
            if (tr[u].son[i]) {
                tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                tr[tr[tr[u].fail].son[i]].du++;
                q.push(tr[u].son[i]);
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];
        }
    }
    std::string t;  std::cin >> t;
    int u = 0;
    for (auto x : t) {
        u = tr[u].son[x - 'a'];
        tr[u].cnt++;
    }
    std::vector<int> ans(n + 1);
    for (int i = 1;i <= tr.size() - 1;i++)
        if (tr[i].du == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans[tr[u].idx] = tr[u].cnt;
        int v = tr[u].fail;
        tr[v].cnt += tr[u].cnt;
        if (!--tr[v].du) q.push(v);
    }
    for (int i = 1; i <= n;i++)
        std::cout << ans[to[i]] << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}