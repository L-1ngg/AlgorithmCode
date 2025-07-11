#include <bits/stdc++.h>
const int MAXN = 2e5;
struct node {
    int l, r, val;
    bool operator <(const node& n) const {
        if (l == n.l) return r < n.r;
        return l < n.l;
    }
};
void solve()
{
    std::map<int, int> mp;
    std::set<node> st;
    mp[0] = MAXN;
    st.insert({ 0, MAXN,0 });

    int q;  std::cin >> q;
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        auto L = st.lower_bound({ l,MAXN,0 });
        auto R = st.lower_bound({ r + 1,MAXN,0 });
        L--, R--;
        int l1 = L->l, r1 = L->r, val1 = L->val;
        int l2 = R->l, r2 = R->r, val2 = R->val;

        std::vector<node> del;
        for (auto it = L;;it++) {
            del.emplace_back(*it);
            if (it == R) break;
        }
        for (auto& d : del) {
            int l = d.l, r = d.r, val = d.val;
            mp[val]--;
            if (mp[val] == 0) mp.erase(val);
            st.erase(d);
        }
        if (l1 < l) {
            st.insert({ l1,l - 1, val1 });
            mp[val1]++;
        }
        if (r < r2) {
            st.insert({ r + 1,r2,val2 });
            mp[val2]++;
        }
        st.insert({ l,r,x });
        mp[x]++;
        std::cout << mp.size() << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();
}