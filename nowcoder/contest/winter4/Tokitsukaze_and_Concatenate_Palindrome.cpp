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
    int n, m;   std::cin >> n >> m;
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int freq1[26] = { 0 }, freq2[26] = { 0 };
    for (auto x : s1)
        freq1[x - 'a']++;
    for (auto x : s2)
        freq2[x - 'a']++;

    // int len1 = n, len2 = m;
    for (int i = 0; i < 26; i++)
    {
        int cnt = std::min(freq1[i], freq2[i]);
        freq1[i] -= cnt;
        freq2[i] -= cnt;
        n -= cnt, m -= cnt;
    }

    if (n == m)
    {
        std::cout << n << '\n';
    }
    else
    {
        int ans = n + m;
        // std::cout << n << " " << m;
        int d = std::abs(n - m);

        // if (d & 1)
        //     d--, ans--;

        int i = 0;
        if (n > m)
            while (d >= 1 && i < 26)
            {
                if ((d & 1) && (freq1[i] & 1))
                    d--, freq1[i]--;

                if (freq1[i] >= 2)
                {
                    ans -= std::min(d, (freq1[i] - (freq1[i] & 1)));
                    d -= (freq1[i] - (freq1[i] & 1));
                }
                i++;
            }
        else
        {
            while (d >= 1 && i < 26)
            {
                if ((d & 1) && (freq2[i] & 1))
                    d--, freq2[i]--;
                if (freq2[i] >= 2)
                {
                    ans -= std::min(d, (freq2[i] - (freq2[i] & 1)));
                    d -= (freq2[i] - (freq2[i] & 1));
                }
                i++;
            }
        }
        std::cout << ans / 2 << '\n';
    }
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