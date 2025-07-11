#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e5 + 5;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

const int MAX_MAT = 2;

struct Mat
{
    i64 a[MAX_MAT][MAX_MAT];
    Mat() { memset(a, 0, sizeof a); for (int i = 0;i < MAX_MAT;i++)a[i][i] = 1; }
    Mat(i64 a1, i64 a2, i64 a3, i64 a4) {
        a[0][0] = a1;a[0][1] = a2;
        a[1][0] = a3;a[1][1] = a4;
    }


};

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)
i64 A[MAX_MAT][MAX_MAT << 1];
void row_minus(int a, int b, i64 k)
{
    for (int i = 0; i < 2 * MAX_MAT; ++i)
    {
        A[a][i] = (A[a][i] - A[b][i] * k % mod) % mod;
        if (A[a][i] < 0)A[a][i] += mod;
    }
    return;
}
void row_multiplies(int a, i64 k)
{
    for (int i = 0; i < 2 * MAX_MAT; ++i)
    {
        A[a][i] = (A[a][i] * k) % mod;
    }
    return;
}
void row_swap(int a, int b)
{
    for (int i = 0; i < 2 * MAX_MAT; ++i)
    {
        std::swap(A[a][i], A[b][i]);
    }
}
Mat getinv(Mat x)
{
    memset(A, 0, sizeof(A));
    for (int i = 0; i < MAX_MAT; ++i)
    {
        for (int j = 0; j < MAX_MAT; ++j)
        {
            A[i][j] = x.a[i][j];
            A[i][MAX_MAT + j] = i == j;
        }
    }
    for (int i = 0; i < MAX_MAT; ++i)
    {
        if (!A[i][i])
        {
            for (int j = i + 1; j < MAX_MAT; ++j)
            {
                if (A[j][i])
                {
                    row_swap(i, j);
                    break;
                }
            }
        }
        row_multiplies(i, inv(A[i][i]));
        for (int j = i + 1; j < MAX_MAT; ++j)
        {
            row_minus(j, i, A[j][i]);
        }
    }
    for (int i = MAX_MAT - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            row_minus(j, i, A[j][i]);
        }
    }
    Mat ret;
    for (int i = 0; i < MAX_MAT; ++i)
    {
        for (int j = 0; j < MAX_MAT; ++j)
        {
            ret.a[i][j] = A[i][MAX_MAT + j];
        }
    }
    return ret;
}

Mat operator * (Mat x, Mat y)
{
    Mat c;
    for (int i = 0; i < MAX_MAT; ++i) {
        for (int j = 0; j < MAX_MAT; ++j) {
            c.a[i][j] = 0;
        }
    }
    for (int i = 0; i < MAX_MAT; ++i) {
        for (int j = 0; j < MAX_MAT; ++j) {
            for (int k = 0; k < MAX_MAT; ++k) {
                c.a[i][j] = (c.a[i][j] + x.a[i][k] * y.a[k][j] % mod) % mod;
            }
        }
    }
    return c;
}

Mat presum[N];
Mat ta = Mat(1, 1, 0, 1);
Mat tb = Mat(1, 0, 1, 1);

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::string s;  std::cin >> s;
    s = " " + s;
    presum[0] = { 1,0,0,1 };
    for (int i = 1; i <= n; i++)
    {
        presum[i] = presum[i - 1] * (s[i] == '/' ? ta : tb);
    }

    for (int i = 1; i <= m;i++)
    {
        int hs, ht, ps, pt;
        std::cin >> hs >> ht >> ps >> pt;
        Mat ans = getinv(presum[hs - 1]) * presum[ht - 1];
        std::cout << ans.a[ps][pt] << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}