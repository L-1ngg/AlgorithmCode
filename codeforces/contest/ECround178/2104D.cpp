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
const int N = 1e7;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<int> pri;
int not_prime[N + 1];

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
    std::vector<i64> a(n);
    for (auto& x : a)   std::cin >> x;
    ranges::sort(a);
    i64 sum = 0;
    int i;
    for (i = 0;i < n;i++) {
        if (a[n - i - 1] >= pri[i])
            sum += a[n - i - 1] - pri[i];
        else {
            if (sum >= pri[i] - a[n - i - 1]) {
                sum -= (-a[n - i - 1] + pri[i]);
            }
            else break;
        }
    }
    std::cout << n - i << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    pre(N);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}