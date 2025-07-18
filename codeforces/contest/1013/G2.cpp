#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

namespace ranges = std::ranges;
namespace views = std::views;

void solve() {
    int s, k;
    std::cin >> s >> k;

    if (s % k == 0) {
        std::cout << k << "\n";
        return;
    }

    if (s > k * k) {
        std::cout << std::max(1, k - 2) << "\n";
        return;
    }

    std::vector<int> f(s + 1);
    f[0] = true;
    for (int i = k; i >= 1; i--) {
        if ((k - i) % 2 == 0) {
            for (int x = s; x >= 0; x--) {
                f[x] = x >= i && f[x - i];
            }
            for (int x = i; x <= s; x++) {
                f[x] = f[x] || f[x - i];
            }
        }
        else {
            for (int x = 0; x <= s; x++) {
                f[x] = x + i <= s && f[x + i];
            }
            for (int x = s - i; x >= 0; x--) {
                f[x] = f[x] || f[x + i];
            }
        }
        if (f[s]) {
            std::cout << i << "\n";
            return;
        }
    }

    std::cout << 1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
