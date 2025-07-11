/*
1 > N
i > j

1,3  2,4
2,4  1,3
2 3  1
1,2,3,4 5

1,n
1      n
*/
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
    std::string s;  std::cin >> s;
    std::set<int> v1, v2;
    for (int i = 1; i <= n;i++) {
        if (s[i - 1] == 'A') v1.insert(i);
        else v2.insert(i);
    }

    if (s == "AB") std::cout << "Alice";
    else if (s == "BA") std::cout << "Bob";
    else if (v1.count(1) && v1.count(n)) std::cout << "Alice";
    else if (v2.count(1) && v2.count(n)) std::cout << "Bob";
    else if (v2.size() == 1) std::cout << "Alice";
    else if (v1.count(n) && v1.count(n - 1)) std::cout << "Alice";
    else std::cout << "Bob";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
}