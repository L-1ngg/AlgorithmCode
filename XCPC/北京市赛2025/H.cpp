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

void solve()
{
    int n, m, p;    std::cin >> n >> m >> p;

    // std::bitset<2000> mat[1000];
    std::vector<std::bitset<2000>> mat(n);
    // 读取矩阵
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++) {
            int x; std::cin >> x;
            mat[i][j] = x;
        }
    for (int i = 0;i < n;i++)
        for (int j = m;j < m + p;j++) {
            int x; std::cin >> x;
            mat[i][j] = x;
        }
    //高斯消元
    int c, r;
    for (c = 0, r = 0;c < m;c++) {
        int t = r;
        for (int i = r;i < n;i++)
            if (mat[i][c] == 1) { t = i; break; }
        if (mat[t][c] == 0) continue;
        std::swap(mat[t], mat[r]);
        for (int i = r + 1;i < n;i++) {
            if (mat[i][c] == 1)
                mat[i] ^= mat[r];
        }
        r++;
    }

    for (int i = r;i < n;i++)
        for (int j = m;j < m + p;j++)
            if (mat[i][j] == 1 && r < n) {
                std::cout << "No\n";
                return;
            }
    std::cout << "Yes\n";
    std::bitset<1000> B[1000];
    for (int i = r - 1;i >= 0;i--) {
        int pivot_col = -1;
        for (int j = 0; j < m; ++j) {
            if (mat[i][j]) {
                pivot_col = j;
                break;
            }
        }
        // 对于 B 的每一列 k
        for (int k = 0; k < p; ++k) {
            int val = mat[i][m + k];
            for (int j = pivot_col + 1; j < m; ++j) {
                if (mat[i][j]) {
                    val ^= B[j][k];
                }
            }
            B[pivot_col][k] = val;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            std::cout << B[i][j] << (j == p - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();
}