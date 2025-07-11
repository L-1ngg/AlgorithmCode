#include <bits/stdc++.h>
using namespace std;

// std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    srand(time(0));
    int x, y;
    x = rand() * rand();
    y = rand() * rand();
    std::cout << x << ' ' << y << endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}