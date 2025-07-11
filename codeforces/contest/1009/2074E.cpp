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

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int ask(int x, int y, int z)
{
    std::cout << "? " << x << ' ' << y << ' ' << z << std::endl;
    int tmp;    std::cin >> tmp;
    return tmp;
}
void ans(int x, int y, int z)
{
    std::cout << "! " << x << ' ' << y << ' ' << z << std::endl;
}

void solve()
{
    int n;  std::cin >> n;
    int q[3] = { 1,2,3 };
    while (1)
    {
        int tmp = ask(q[0], q[1], q[2]);
        if (tmp == 0)    break;
        q[rng() % 3] = tmp;
    }
    ans(q[0], q[1], q[2]);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}