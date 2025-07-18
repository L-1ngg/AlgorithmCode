#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using i64 = long long;
using V = pair<i64, int>;
using Ver = tree<V, null_type, less<V>, rb_tree_tag, tree_order_statistics_node_update>;
void solve()
{
    Ver ver;
    int n, q;   std::cin >> n >> q;
    std::vector<i64> a(n + 1);
    for (int i = 1;i <= n;i++) std::cin >> a[i], ver.insert({ a[i],i });

    int pos = (n / 2);
    while (q--) {
        int p, v;   std::cin >> p >> v;
        ver.erase({ a[p],p });
        a[p] += v;
        ver.insert({ a[p],p });
        auto it = ver.find_by_order(n - pos);
        std::cout << ver.order_of_key({ it->first ,0 }) << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
}