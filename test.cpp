#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
const int M = 1e5 + 100;

struct N {
    ll id, hi;
}h[M];

bool cmp(N a, N b) {
    return a.hi < b.hi;
}

void solve() {
    ll n, k; cin >> n >> k;
    memset(h, 0, sizeof(h));
    ll pos = 0;
    ll maxn = 0;
    for (int i = 1;i <= n;i++) { cin >> h[i].hi; h[i].id = i; maxn = max(maxn, h[i].hi); }
    sort(h + 1, h + n + 1, cmp);
    for (int i = 0;i <= n;i++) if (h[i].id == k) pos = i;
    // cout << pos << "\n";
    ll res = h[pos].hi;
    for (int i = pos + 1;i <= n;i++) {
        if (h[i].hi - h[i - 1].hi > res) { cout << "NO\n"; return; }
        // if (maxn == h[i].hi) { cout << "YES\n"; return; }
        // ll tim = h[i].hi - h[i - 1].hi;
        // res = res - tim + (h[i].hi - h[i - 1].hi);
    }
    cout << "YES\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}