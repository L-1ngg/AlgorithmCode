#include<bits/stdc++.h>
using namespace std;
const int MAX_MAT = 2;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 61;
const int MAXN = 100005;
char s[MAXN];
long long val[MAXN][3];

struct Mat
{
    long long a[MAX_MAT][MAX_MAT];
    Mat()
    {
        for (int i = 0; i < MAX_MAT; ++i)
        {
            for (int j = 0; j < MAX_MAT; ++j)
            {
                a[i][j] = INF;
            }
        }
        for (int i = 0; i < MAX_MAT; ++i)
        {
            a[i][i] = 0;
        }
    }
    Mat(long long a1, long long a2, long long a3, long long a4)
    {
        a[0][0] = a1;
        a[0][1] = a2;
        a[1][0] = a3;
        a[1][1] = a4;
    }
};

Mat operator * (Mat x, Mat y)
{
    Mat c;
    for (int i = 0; i < MAX_MAT; ++i) {
        for (int j = 0; j < MAX_MAT; ++j) {
            c.a[i][j] = INF;
        }
    }
    for (int i = 0; i < MAX_MAT; ++i) {
        for (int j = 0; j < MAX_MAT; ++j) {
            for (int k = 0; k < MAX_MAT; ++k) {
                c.a[i][j] = min(c.a[i][j], x.a[i][k] + y.a[k][j]);
            }
        }
    }
    return c;
}

Mat make_dp_mat(int x)
{
    if (s[x] == '/')
    {
        return Mat(val[x][0], val[x][2], INF, val[x][1]);
    }
    else
    {
        return Mat(val[x][0], INF, val[x][2], val[x][1]);
    }
}
struct tnode
{
    Mat mat;
    int l, r;
};
struct Segment_Tree
{
    tnode t[4 * MAXN];
    int pos[MAXN];
    void update(int root)
    {
        int ch = root << 1;
        t[root].mat = t[ch].mat * t[ch + 1].mat;
    }
    void build(int root, int l, int r)
    {
        t[root].l = l;
        t[root].r = r;
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
            t[root].mat = make_dp_mat(l);
            pos[l] = root;
        }
    }
    void change(int x)
    {
        int root = pos[x];
        t[root].mat = make_dp_mat(x);
        while (root >>= 1)update(root);
    }
    Mat query(int root, int l, int r)
    {
        if (t[root].l == l && t[root].r == r)
        {
            return t[root].mat;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)return query(ch, l, r);
        else if (l > mid)return query(ch + 1, l, r);
        else return query(ch, l, mid) * query(ch + 1, mid + 1, r);
    }
};
Segment_Tree ST;
int n, m, hs, ht, ps, pt, op, x;
char c[5];
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1;i < n;++i)
    {
        scanf("%lld %lld %lld", &val[i][0], &val[i][1], &val[i][2]);
    }
    ST.build(1, 1, n - 1);
    while (m--)
    {
        scanf("%d", &op);
        if (op == 2)
        {
            scanf("%d %d %d %d", &hs, &ht, &ps, &pt);
            long long ans = ST.query(1, hs, ht - 1).a[ps][pt];
            if (ans == INF)ans = -1;
            printf("%lld\n", ans);
        }
        else
        {
            if (op == 0)
            {
                scanf("%d %s", &x, c);
                s[x] = *c;
            }
            else
            {
                scanf("%d", &x);
                scanf("%lld %lld %lld", &val[x][0], &val[x][1], &val[x][2]);
            }
            ST.change(x);
        }
    }
    return 0;
}
/*

4 13
///
1 2 1
2 3 5
8 8 1
2 1 4 1 0
0 3 \
2 1 4 0 0
2 2 4 0 0
2 2 4 0 1
2 3 4 0 1
2 3 4 1 0
1 1 1 1 1
1 2 1 1 1
1 3 1 1 1
2 1 4 1 0
0 3 /
2 1 4 1 0

*/