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
const int MAXN = 3000005;
const int inf = 1e9;
const i64 INF = 9114511145141919810;
const int mod = 1e9 + 7;

struct Element {
    int x, y, z;
    int type; // 1 表示点, 2 表示查询
    int id;
};

int n, q;
std::vector<Element> elements;
std::vector<i64> ans;
std::vector<int> bit(MAXN, 0);

void add(int idx, int val) {
    for (; idx < MAXN; idx += idx & -idx) {
        bit[idx] += val;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

void cdq(int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    cdq(left, mid);
    cdq(mid + 1, right);

    //归并排序
    std::vector<Element> temp;

    int p1 = left;
    int p2 = mid + 1;

    while (p1 <= mid || p2 <= right) {
        if (p1 > mid || (p2 <= right && elements[p1].y < elements[p2].y)) {
            // 如果type = 2，计算贡献
            if (elements[p2].type == 2) {
                ans[elements[p2].id] += query(elements[p2].z);
            }
            temp.push_back(elements[p2]);
            p2++;
        }
        else {
            // 如果type = 1，加入树状数组
            if (elements[p1].type == 1) {
                add(elements[p1].z, 1);
            }
            temp.push_back(elements[p1]);
            p1++;
        }
    }

    // 清理树状数组
    for (int i = left; i <= mid; ++i) {
        if (elements[i].type == 1) {
            add(elements[i].z, -1);
        }
    }

    // 归并排序
    for (int i = 0; i < temp.size(); ++i) {
        elements[left + i] = temp[i];
    }
}

void solve()
{
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        elements.push_back({ x, y, x + y, 1, -1 });
    }

    ans.resize(q);
    for (int i = 0; i < q; ++i) {
        int x, y, d;
        std::cin >> x >> y >> d;
        elements.push_back({ x, y, x + y + d, 2, i });
    }

    std::sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
        if (a.x != b.x) return a.x > b.x;
        return a.y > b.y;
        });

    cdq(0, n + q - 1);

    for (int i = 0; i < q; ++i)
        std::cout << ans[i] << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}