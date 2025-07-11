#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

int num;
int a[45], n = 0;
int ans = inf;

void dfs(int step, int cnt, int now, int tmp) {
    if (cnt >= ans || now + tmp > num || cnt >= n) return;
    if (step > n) {
        if (now + tmp == num)
            ans = std::min(cnt, ans);
        return;
    }
    dfs(step + 1, cnt + 1, now + tmp, a[step]);
    dfs(step + 1, cnt, now, tmp * 10 + a[step]);
}
void solve()
{
    std::string str;
    std::cin >> str >> num;

    int f = 0;
    for (auto x : str) {
        if (x != '0')
            f = 1;
        if (f) a[++n] = x - '0';
    }

    dfs(1, 0, 0, 0);
    std::cout << (ans == inf ? -1 : ans);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}