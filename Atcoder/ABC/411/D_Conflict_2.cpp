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
const int N = 1e6 + 50;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<int> a(N), fa(N + 1);
std::vector<std::string> s(N);

void dfs(int x) {
    if (!x) return;
    dfs(fa[x]);
    std::cout << s[x];
}

void solve()
{
    int n, q;   std::cin >> n >> q;
    int cnt = 0, now = 0;
    //1 a[x] = now
    //2 new {cnt++, -> x,a[x] == cnt}
    //3 now = a[x]
    while (q--) {
        int op, x;  std::cin >> op >> x;
        if (op == 1) a[x] = now;
        else if (op == 2) {
            std::cin >> s[++cnt];
            fa[cnt] = a[x];
            a[x] = cnt;
        }
        else now = a[x];
    }
    dfs(now);
    std::cout << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}