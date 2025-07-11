/*
https://atcoder.jp/contests/abc392/tasks/abc392_e
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

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    std::vector<std::vector<a3>> amari;
    UnionFind(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        amari.resize(n);
        // for (int i = 0; i < n; i++) {
        //     parent[i] = i;
        // }
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] > rank[rootY]) {
            std::swap(rootX, rootY);
        }

        amari[rootY].insert(amari[rootY].end(), amari[rootX].begin(), amari[rootX].end());
        amari[rootX].clear();

        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) {
            rank[rootY]++;
        }
    }

    bool isConnect(int x, int y) {
        return find(x) == find(y);
    }
};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    UnionFind dsu(n);
    for (int i = 1; i <= m; i++)
    {
        int x, y;   std::cin >> x >> y;
        x--, y--;
        if (dsu.isConnect(x, y))
            dsu.amari[dsu.find(x)].emplace_back(a3{ x, y, i });
        else
            dsu.merge(x, y);
    }

    std::vector<pii> cc;
    for (int i = 0; i < n; i++)
    {
        if (i == dsu.find(i))
            cc.emplace_back(dsu.amari[i].size(), i);
    }

    std::sort(cc.rbegin(), cc.rend());

    std::cout << cc.size() - 1 << '\n';
    int pos = 1;
    for (auto [_, root] : cc)
    {
        for (auto [x, y, i] : dsu.amari[root])
            if (pos < cc.size())
                std::cout << i << ' ' << x + 1 << ' ' << cc[pos++].second + 1 << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}