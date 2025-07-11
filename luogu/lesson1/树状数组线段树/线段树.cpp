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
const int MAXN = 1e5 + 10;
const int inf = 1e9;


int p;

int a[MAXN];
struct tnode {
    i64 ji, sum, a, b;
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
        t[ch].a = t[ch].a * t[fa].a % p;
        t[ch].b = t[fa].a * t[ch].b % p + t[fa].b % p;
    }
    void cal_lazy(int root)
    {
        int a = t[root].a, b = t[root].b;
        int len = (t[root].r - t[root].l + 1) % p;

        t[root].ji = a * a % p * t[root].ji % p +
            a * b % p * t[root].sum % p * (len - 1) % p +
            b * b % p * len * (len - 1) / 2 % p;

        t[root].sum = (a * t[root].sum % p + len * b % p) % p;
    }

    void push_down(int root)
    {
        if (t[root].a != 1 || t[root].b != 0)
        {
            cal_lazy(root);
            if (t[root].l != t[root].r) {
                int ch = root << 1;
                union_lazy(root, ch);
                union_lazy(root, ch + 1);
            }
            init_lazy(root);
        }
    }

    void update(int root)
    {
        int ch = root << 1;
        push_down(ch);
        push_down(ch + 1);
        t[root].sum = (t[ch].sum + t[ch + 1].sum) % p;
        t[root].ji = (t[ch].ji + t[ch + 1].ji % p + t[ch].sum * t[ch + 1].sum % p) % p;
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
            t[root].sum = a[l] % p;
            t[root].ji = 0;
        }
    }

    void change(int root, int l, int r, int x, int op) {
        push_down(root);
        if (l == t[root].l && r == t[root].r)
        {
            if (op == 1)
                t[root].b = x;
            else
                t[root].a = x;
            return;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)   change(ch, l, r, x, op);
        else if (l > mid) change(ch + 1, l, r, x, op);
        else
        {
            change(ch, l, mid, x, op), change(ch + 1, mid + 1, r, x, op);
        }
        update(root);
    }

    i64 getji(int root, int l, int r)
    {
        push_down(root);
        if (l == t[root].l && r == t[root].r)
        {
            return t[root].ji % p;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid) return getji(ch, l, r) % p;
        else if (l > mid) return getji(ch + 1, l, r) % p;
        else
            return (getji(ch, l, mid) + getji(ch + 1, mid + 1, r)) % p;
    }
};

Segment_tree tr;
void solve()
{
    int n, m;
    std::cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    tr.build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, l, r, x;
        std::cin >> op;
        if (op <= 2)
        {
            std::cin >> l >> r >> x;
            tr.change(1, l, r, x, op);
        }
        else {
            std::cin >> l >> r;
            std::cout << tr.getji(1, l, r) << '\n';
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