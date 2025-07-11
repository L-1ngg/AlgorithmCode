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

struct tnode
{
    i64 sum1, sum2, a, b;
    int l, r;
};

struct Segment_tree
{
    tnode t[MAXN << 2];
    void init_lazy(int root)
    {
        t[root].a = 1;
        t[root].b = 0;
    }
    void union_lazy(int fa, int ch)
    {
        t[ch].a = t[ch].a * t[fa].a;
        t[ch].b = t[fa].a * t[ch].b + t[fa].b;
    }
    void cal_lazy(int root)
    {
        t[root].sum2 = t[root].b * t[root].b * (t[root].r - t[root].l + 1) +
            2ll * t[root].a * t[root].b * t[root].sum1 +
            t[root].a * t[root].a * t[root].sum2;

        t[root].sum1 = t[root].a * t[root].sum1 +
            (t[root].r - t[root].l + 1) * t[root].b;
    }
    void push_down(int root)
    {
        if (t[root].a != 1 || t[root].b != 0)
        {
            cal_lazy(root);
            if (t[root].l != t[root].r)
            {
                int ch = root << 1;
                union_lazy(root, ch);
                union_lazy(root, ch + 1);
            }
            init_lazy(root);
        }
    }
    void update(int root)
    {
        int  ch = root << 1;
        push_down(ch);
        push_down(ch + 1);
        t[root].sum1 = t[ch].sum1 + t[ch + 1].sum1;
        t[root].sum2 = t[ch].sum2 + t[ch + 1].sum2;
    }
    void build(int root, int l, int r)
    {
        t[root].l = l;
        t[root].r = r;
        init_lazy(root);
        if (l != r)
        {
            int mid = (l + r) >> 1;
            int ch = root << 1;
            build(ch, l, mid);
            build(ch + 1, mid + 1, r);
            update(root);
        }
        else
        {
            t[root].sum1 = a[l];
            t[root].sum2 = a[l] * a[l];
        }
    }
    void change(int root, int l, int r, i64 delta, int op)
    {
        push_down(root);
        if (l == t[root].l && r == t[root].r)
        {
            if (op == 3)
                t[root].a = delta;
            else
                t[root].b = delta;
            return;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid) change(ch, l, r, delta, op);
        else if (l > mid) change(ch + 1, l, r, delta, op);
        else {
            change(ch, l, mid, delta, op), change(ch + 1, mid + 1, r, delta, op);
        }
        update(root);
    }

    i64 sum(int root, int l, int r, int op)
    {
        push_down(root);
        if (l == t[root].l && r == t[root].r)
        {
            if (op == 1)
                return t[root].sum1;
            else
                return t[root].sum2;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)
            return sum(ch, l, r, op);
        else if (l > mid)
            return sum(ch + 1, l, r, op);
        else
        {
            return sum(ch, l, mid, op) + sum(ch + 1, mid + 1, r, op);
        }
    }
};


Segment_tree tr;
void solve()
{
    int n, m;   std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    tr.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int l, r, op, x;
        std::cin >> op;
        if (op == 1 || op == 2)
        {
            std::cin >> l >> r;
            std::cout << tr.sum(1, l, r, op) << '\n';
        }
        else {
            std::cin >> l >> r >> x;
            tr.change(1, l, r, x, op);
        }

    }

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}