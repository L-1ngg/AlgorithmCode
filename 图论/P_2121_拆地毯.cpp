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

struct DSU{
    std::vector<int> d;
    DSU(int n) {d.resize(n + 1);std::iota(d.begin(),d.end(),0);}
    int find(int x) {return d[x] = (x == d[x] ? x : find(d[x]));}
    void merge(int x,int y){
        d[find(x)] = find(y);
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

struct Tree {
    using TII = std::tuple<int, int, int>;
    int n;
    std::priority_queue<TII, std::vector<TII>, std::less<TII>> ver;
    Tree(int n) {
        this->n = n;
    }

    void add(int x, int y, int w) {
        ver.push({ w,x,y });
    }

    int kruskql(int k) {
        DSU dsu(n);
        int ans = 0, cnt = 0;
        while (!ver.empty() && cnt != k) {
            auto [w, x, y] = ver.top();
            ver.pop();
            if (dsu.same(x, y)) continue;
            dsu.merge(x, y);
            ans += w;
            cnt++;
        }
        if (cnt < k) return -1;
        return ans;
    }
};


void solve()
{
  int n,m,k;       std::cin >> n >> m >> k;
    Tree tr(n);
  for(int i = 1;i <= m;i++){
        int u,v,w;  std::cin >> u >> v >> w;
        tr.add(u,v,w);
  }
  std::cout << tr.kruskql(k);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
        solve();
}