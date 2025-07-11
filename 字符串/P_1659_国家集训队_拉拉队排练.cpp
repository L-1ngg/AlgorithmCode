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
const int mod = 19930726;


std::vector<int> manacher(std::string s) {
    std::string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    std::vector<int> r(n);
    for (int i = 0, j = 0; i < n; i++) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = std::min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

i64 qpow(i64 x, i64 b) {
    i64 ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}
void solve()
{
    i64 n, k;   std::cin >> n >> k;
    std::string s;  std::cin >> s;
    std::vector<int> a = manacher(s);
    i64 sum = 0;
    std::map<int, int> mp;
    for (int i = 0;i < a.size();i++) {
        if (i & 1)  mp[a[i] - 1]++, sum += (a[i] / 2);
    }
    if (sum < k) {
        std::cout << "-1";
        return;
    }

    i64 res = 1;
    auto it = mp.end();
    while (k > 0) {
        if (k >= it->second)
        {
            res = res * qpow(it->first, it->second) % mod;
            if (it->first > 1) mp[it->first - 2] += it->second;
        }
        else
            res = res * qpow(it->first, k) % mod;
        k -= it->second;
        it--;
    }
    std::cout << res;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}