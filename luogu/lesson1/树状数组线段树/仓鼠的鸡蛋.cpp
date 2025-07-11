//https://ac.nowcoder.com/acm/contest/19684/H
// 这是一个线段树二分问题

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

int cnt[MAXN];
int n, m, k;

struct tnode {
    int max;
    int l, r;
};

struct Segment_tree {
    tnode t[MAXN << 2];

    void update(int root) {
        int ch = root << 1;
        t[root].max = std::max(t[ch].max, t[ch + 1].max);
    }

    void build(int root, int l, int r)
    {
        t[root].l = l;
        t[root].r = r;

        if (l == r)
        {
            t[root].max = m;
            cnt[l] = 0;
        }
        else
        {
            int ch = root << 1;
            int mid = (l + r) >> 1;
            build(ch, l, mid);
            build(ch + 1, mid + 1, r);
            update(root);
        }
    }

    int change(int x)
    {
        int root = 1;
        while (t[root].l != t[root].r)
        {
            int ch = root << 1;
            if (t[ch].max >= x)
                root <<= 1;
            else
                root = (root << 1) + 1;
        }

        t[root].max -= x;
        cnt[t[root].l]++;
        if (cnt[t[root].l] == k)
            t[root].max = 0;

        int res;
        res = t[root].l;

        root >>= 1;
        while (root)
        {
            update(root);
            root >>= 1;
        }
        return res;
    }
};

Segment_tree tr;
void solve()
{
    // memset(cnt, 0, sizeof cnt);
    std::cin >> n >> m >> k;
    tr.build(1, 1, n);
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> tmp;
        if (tr.t[1].max < tmp)
            std::cout << "-1\n";
        else
        {
            int ans = tr.change(tmp);
            std::cout << ans << '\n';
        }
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