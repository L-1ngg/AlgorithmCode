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
    int n;  std::cin >> n;
    std::stack<int> st;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;

    for (int i = 1; i <= n;i++) {
        int x;  std::cin >> x;
        while (!st.empty() && x < st.top()) {
            pq.push(st.top() + 1);
            st.pop();
        }
        st.push(x);
    }

    while (!pq.empty()) {
        while (!st.empty() && pq.top() < st.top()) {
            pq.push(st.top() + 1);
            st.pop();
        }
        st.push(pq.top());
        pq.pop();
    }
    std::vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for (int i = n - 1;i >= 0;i--) {
        std::cout << ans[i] << " \n"[i == 0];
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