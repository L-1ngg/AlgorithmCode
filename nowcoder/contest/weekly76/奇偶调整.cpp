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
const int MAXN = 1e9 + 10;
const int inf = 1e9;

struct Compare {
    bool operator()(const pii& a, const pii& b) const {
        return a.first < b.first;
    }
};

void solve()
{
    int n, m, k;    std::cin >> n >> m >> k;
    std::unordered_map<int, int> map;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        map[tmp]++;
    }

    std::priority_queue<pii, std::vector<pii>, Compare> pq;
    for (const auto& [v, c] : map)
    {
        pq.emplace(v, c);
    }

    i64 ans = 0;

    while ((!pq.empty()) && (m > 0 || k > 0))
    {
        auto [u, cnt] = pq.top();
        pq.pop();

        if (u & 1)
        {
            if (k > 0)
            {
                int opcnt = std::min(k, cnt);
                if (u - 1 > 0)
                {
                    if (!pq.empty() && pq.top().first == (u - 1))
                    {
                        auto top = pq.top(); pq.pop();
                        pq.emplace(u - 1, top.second + opcnt);
                    }
                    else
                    {
                        pq.emplace(u - 1, opcnt);
                    }
                }
                if (cnt > opcnt)
                {
                    ans += (i64)u * (cnt - opcnt);
                }
                k -= opcnt;
            }
            else
            {
                ans += (i64)u * cnt;
            }
        }
        else
        {
            if (m > 0)
            {
                int opcnt = std::min(m, cnt);
                if (u / 2 > 0)
                {
                    if (!pq.empty() && pq.top().first == (u / 2))
                    {
                        auto top = pq.top(); pq.pop();
                        pq.emplace(u / 2, top.second + opcnt);
                    }
                    else
                    {
                        pq.emplace(u / 2, opcnt);
                    }
                }
                if (cnt > opcnt)
                {
                    ans += (i64)u * (cnt - opcnt);
                }
                m -= opcnt;
            }
            else
                ans += (i64)u * cnt;

        }
        if (!m && !k)
            break;
    }
    while (!pq.empty())
    {
        auto [u, cnt] = pq.top(); pq.pop();
        ans += (i64)u * cnt;
    }

    std::cout << ans;
}




signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}