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

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)  std::cin >> x;
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (a[(i + k) % n] == a[(j + k) % n])  ++k;
        else {
            a[(i + k) % n] > a[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            k = 0;
            if (i == j) i++;
        }
    }
    i = std::min(i, j);
    k = 0;
    while (k < n) {
        std::cout << a[(i + k) % n] << " ";
        ++k;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}