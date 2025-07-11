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

int a[MAXN];
int n, m;

struct tnode {
    int min, lazy;
    int l, r;
};

struct Segment_tree {
    tnode t[MAXN << 2];
    bool f = 1;

    void push_down(int root)
    {
        if (t[root].lazy != 0)
        {
            t[root].min -= t[root].lazy;
            if (t[root].l != t[root].r) {
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
        t[root].min = std::min(t[ch].min, t[ch + 1].min);
    }

    void build(int root, int l, int r) {
        t[root].l = l;
        t[root].r = r;
        t[root].lazy = 0;
        f = 1;

        if (l == r)
            t[root].min = a[l];
        else
        {
            int ch = root << 1;
            int mid = (l + r) >> 1;
            build(ch, l, mid);
            build(ch + 1, mid + 1, r);
            update(root);
        }
    }
    void change(int root, int l, int r, int x)
    {
        push_down(root);
        if (t[root].l == l && t[root].r == r)
        {
            if (t[root].min >= x)
                t[root].lazy += x;
            else
                f = 0;
            return;
        }

        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (mid >= r)
            change(ch, l, r, x);
        else if (mid < l)
            change(ch + 1, l, r, x);
        else
            change(ch, l, mid, x), change(ch + 1, mid + 1, r, x);
        update(root);
    }
};


Segment_tree tr;
void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n;i++)
        std::cin >> a[i];
    tr.build(1, 1, n);

    for (int i = 1; i <= m; i++)
    {
        int x, l, r;    std::cin >> x >> l >> r;
        tr.change(1, l, r, x);
        if (tr.f == 0)
        {
            std::cout << i;
            return;
        }
    }
    std::cout << 0;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}