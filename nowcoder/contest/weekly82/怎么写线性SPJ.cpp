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
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1, 0);

    int mx = 0;
    auto build = [&](auto&& self, int l, int r, int cnt) ->void
        {
            if (l == r)
            {
                if (a[l] == 0)
                    a[l] = cnt;
                return;
            }
            int mid = (l + r) >> 1;
            a[mid] = cnt;

            self(self, l, mid, cnt + 1), self(self, mid + 1, r, cnt + 1);
            return;
        };

    build(build, 1, n, 1);
    mx = *std::max_element(a.begin(), a.end());
    std::cout << mx << '\n';
    for (int i = 1; i <= n; i++)
        std::cout << a[i] << ' ';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}