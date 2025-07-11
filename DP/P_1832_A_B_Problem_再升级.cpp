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

std::vector<int> pri;
int not_prime[N];

void pre(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            pri.push_back(i);
        }
        for (int num : pri) {
            if (i * num > n) break;
            not_prime[i * num] = 1;
            if (i % num == 0) {
                break;
            }
        }
    }
}

void solve()
{
    int n;  std::cin >> n;
    pre(n);
    std::vector<i64> f(n + 1, 0);
    f[0] = 1;
    for (auto p : pri) {
        for (int j = p;j <= n;j++)
            f[j] += f[j - p];
    }
    std::cout << f[n];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}