#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e7 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

std::vector<int> prime;
bool is_prime[N];

void Eratosthenes(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) is_prime[i] = true;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
    }
    for (int i = 2; i <= n; ++i)
        if (is_prime[i]) prime.push_back(i);
}

void solve()
{
    int n;  std::cin >> n;
    int ans = 0;

    for (int i = 2; i <= n;i++)
    {
        if (is_prime[i])
            ans += n / i;
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    Eratosthenes(1e7);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}