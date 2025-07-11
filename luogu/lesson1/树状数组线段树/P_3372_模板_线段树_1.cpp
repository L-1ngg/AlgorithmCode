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
const int MAXN = 1e5 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

i64 a[MAXN];
struct tnode {
    i64 sum, lazy;
    int l, r;
};

struct Segment_tree {

    tnode t[MAXN << 2];
    void push_down(int root)
    {
        if (t[root].lazy != 0)
        {
            t[root].sum += (t[root].r - t[root].l + 1) * t[root].lazy;
            if (t[root].l != t[root].r)
            {
                int ch = root << 1;
                t[ch].lazy += t[root].lazy;
                t[ch + 1].lazy += t[root].lazy;
            }
            t[root].lazy = 0;
        }
    }
    void update(int root)
    {
        int ch = root << 1;
        push_down(ch);
        push_down(ch + 1);
        t[root].sum = t[ch].sum + t[ch + 1].sum;
    }
    void build(int root, int l, int r)
    {
        t[root].l = l;
        t[root].r = r;
        t[root].lazy = 0;

        if (l == r) {
            t[root].sum = a[l];
        }
        else {
            int mid = (l + r) >> 1;
            int ch = root << 1;
            build(ch, l, mid);
            build(ch + 1, mid + 1, r);
            update(root);
        }
    }

    void change(int root, int l, int r, i64 x)
    {
        push_down(root);
        if (t[root].l == l && t[root].r == r)
        {
            t[root].lazy = x;
            return;
        }

        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid) change(ch, l, r, x);
        else if (l > mid) change(ch + 1, l, r, x);
        else
        {
            change(ch, l, mid, x);
            change(ch + 1, mid + 1, r, x);
        }
        update(root);

    }

    i64 sum(int root, int l, int r)
    {
        push_down(root);
        if (t[root].l == l && t[root].r == r)
            return t[root].sum;
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;

        if (r <= mid) return sum(ch, l, r);
        else if (l > mid)  return sum(ch + 1, l, r);
        else
            return sum(ch, l, mid) + sum(ch + 1, mid + 1, r);
    }
};

Segment_tree tr;

void solve()
{
    int n, m;   std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    tr.build(1, 1, n);

    for (int i = 1; i <= m; i++)
    {
        i64 op, l, r, k;
        std::cin >> op;
        if (op == 1)
        {
            std::cin >> l >> r >> k;
            tr.change(1, l, r, k);
        }
        else
        {
            std::cin >> l >> r;
            std::cout << tr.sum(1, l, r) << '\n';
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}