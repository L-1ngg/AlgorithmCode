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

void solve()
{
    std::string s = "24:00:00";
    std::string str;    std::cin >> str;

    int s_hours = std::stoi(s.substr(0, 2));
    int s_minutes = std::stoi(s.substr(3, 2));
    int s_seconds = std::stoi(s.substr(6, 2));

    int s_total = s_hours * 3600 + s_minutes * 60 + s_seconds;

    int str_minutes = std::stoi(str.substr(0, 2));
    int str_seconds = std::stoi(str.substr(3, 2));
    int str_total = str_minutes * 60 + str_seconds;

    int diff = s_total - str_total;
    int hh = diff / 3600;
    int mm = (diff % 3600) / 60;
    int ss = diff % 60;
    std::cout << std::setw(2) << std::setfill('0') << hh << ":"
        << std::setw(2) << std::setfill('0') << mm << ":"
        << std::setw(2) << std::setfill('0') << ss;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}