#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

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

i64 a[3][2];
void solve()
{
    i64 n, x, y;
    std::cin >> n >> x >> y;
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;
    std::vector<int> sum(4, 0);

    for (int i = 0; i < n; i++)
    {
        int n1 = s1[i] - '0', n2 = s2[i] - '0';
        int n3 = s3[i] - '0';
        if ((n1 + n2) % 2 != n3)
        {
            if (n1 == 0 && n2 == 0)
                sum[0]++;
            if (n1 == 0 && n2 == 1)
                sum[1]++;
            if (n1 == 1 && n2 == 0)
                sum[2]++;
            if (n1 == 1 && n2 == 1)
                sum[3]++;
        }
    }


    int sum0 = 0;
    ranges::sort(sum.begin(), sum.end());
    // std::cout << sum[0] << sum[3];

    for (int i = 0; i < 3; i++)
        sum0 += sum[i];
    if (x * 2ll <= y)
        std::cout << 1ll * x * (sum0 + sum[3]);
    else
    {
        i64 ans = 0;
        if (sum[3] <= sum0)
        {
            int cnt = sum0 + sum[3];
            ans = 1ll * y * (cnt / 2) + 1ll * x * (cnt & 1);
        }
        else {
            ans = 1ll * y * sum0;
            sum[3] -= sum0;
            ans += 1ll * x * sum[3];
        }
        std::cout << ans;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}