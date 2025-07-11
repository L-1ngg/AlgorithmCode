#include <bits/stdc++.h>
using namespace std; using ll = long long; using u32 = unsigned; using i64 = long long; using u64 = unsigned long long; using i128 = __int128; using u128 = unsigned __int128;
ostream& operator<<(ostream& out, i128 x)
{
    if (x == 0)return out << 0;
    if (x < 0)
    {
        out << "-";
        x = -x;
    }
    vector<int> a;
    while (x) { a.push_back(x % 10);x /= 10; }
    ranges::reverse(a);
    for (auto it : a)out << it;
    return out;
}
template <class T1, class T2> istream& operator>>(istream& in, pair<T1, T2>& p); template <class T> istream& operator>>(istream& in, vector<T>& a);
template <class T, size_t n> istream& operator>>(istream& in, array<T, n>& a);
template <class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p);
template <class T, class = decay_t<decltype(*begin(declval<T>()))>, class = enable_if_t<!is_same<T, string>::value>> ostream& operator<<(ostream& os, const T& c); //C++ 14 顺序容器
template <class T> ostream& operator<<(ostream& os, const vector<T>& c);
template <class T, size_t n> ostream& operator<<(ostream& os, const array<T, n>& c);
template <class T> ostream& operator<<(ostream& os, const list<T>& c);
template <class T> ostream& operator<<(ostream& os, const forward_list<T>& c);
template <class T> ostream& operator<<(ostream& os, const set<T>& c);
template <class T> ostream& operator<<(ostream& os, const multiset<T>& c);
template <class T1, class T2> ostream& operator<<(ostream& os, const map<T1, T2>& c);
template <class T1, class T2> ostream& operator<<(ostream& os, const multimap<T1, T2>& c);
template <class... Args> ostream& operator<<(ostream& os, const priority_queue<Args...>& S);
template <class T> ostream& operator<<(ostream& os, const queue<T>& S);
template <class T> ostream& operator<<(ostream& os, const stack<T>& S);
template <class T> ostream& operator<<(ostream& os, const deque<T>& S);
template <class T1, class T2> istream& operator>>(istream& in, pair<T1, T2>& p) { return in >> p.first >> p.second; }
template <class T> istream& operator>>(istream& in, vector<T>& a) { for (auto& x : a) in >> x; return in; }
template <class T, size_t n> istream& operator>>(istream& in, array<T, n>& a) { for (auto& x : a) in >> x; return in; }
template <class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '[' << p.first << ", " << p.second << ']'; }
template <class T, class, class> ostream& operator<<(ostream& os, const T& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T, size_t n> ostream& operator<<(ostream& os, const array<T, n>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T> ostream& operator<<(ostream& os, const list<T>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T> ostream& operator<<(ostream& os, const forward_list<T>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T> ostream& operator<<(ostream& os, const set<T>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T> ostream& operator<<(ostream& os, const multiset<T>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T1, class T2> ostream& operator<<(ostream& os, const map<T1, T2>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class T1, class T2> ostream& operator<<(ostream& os, const multimap<T1, T2>& c) { os << "["; for (auto it = c.begin(); it != c.end(); ++it) if (it != prev(c.end())) os << *it << ", "; else os << *it; return os << "]"; }
template <class... Args> ostream& operator<<(ostream& os, const priority_queue<Args...>& S) { priority_queue<Args...> s = S; os << "["; while (s.size() > 1) { os << s.top() << ", "; s.pop(); } if (s.size()) { os << s.top(); } os << "]"; return os; }
template <class T> ostream& operator<<(ostream& os, const queue<T>& S) { queue<T> s = S; os << "["; while (s.size() > 1) { os << s.front() << ","; s.pop(); } if (s.size()) { os << s.front(); } os << "]"; return os; }
template <class T> ostream& operator<<(ostream& os, const stack<T>& S) { stack<T> s = S; os << "["; while (s.size() > 1) { os << s.top() << ","; s.pop(); } if (s.size()) { os << s.top(); } os << ">"; return os; }
template <class T> ostream& operator<<(ostream& os, const deque<T>& S) { deque<T> s = S; os << "["; while (s.size() > 1) { os << s.front() << ", "; s.pop_front(); } if (s.size()) { os << s.front(); } os << "]"; return os; }
template <class T> inline long long accumulate(std::vector<T> t) { return std::accumulate(t.begin(), t.end(), 0LL); }
template <class T1, class T2> inline T2 accumulate(T1 t1, T2 t2) { return std::accumulate(t1.begin(), t1.end(), t2); }
template <class T1, class T2, class T3> inline T2 accumulate(T1 t1, T2 t2, T3 t3) { return std::accumulate(t1.begin(), t1.end(), t2, t3); }
template <class... Args> auto varvector(size_t n, Args&&... args) { if constexpr (sizeof...(args) == 1) return std::vector(n, args...); else return std::vector(n, varvector(args...)); } //C++ 17 vector 无模板参数
std::vector<vector<int>> vertices(size_t n) { return std::vector<vector<int>>(n); }
void YESNO(bool b) { cout << (b ? "YES\n" : "NO\n"); }
void YesNo(bool b) { cout << (b ? "Yes\n" : "No\n"); }
#ifndef ONLINE_JUDGE
template <class... Args> void debug(Args... args) { int tot = 1, n = sizeof...(args); auto _ = [&](auto x) -> void { cout << x; if (tot < n) cout << ", "; }; cout << "{"; int arr[] = { (_(args), ++tot)... }; cout << "}\n"; } //C++ 14 lambda 参数 auto
#else
template <class... Args> void debug(Args... args) {}
#endif
void solve()
{
    int n;ll y;
    cin >> n >> y;
    vector<u64> a(n);
    for (int i = 0;i < n;i++)cin >> a[i];
    if (accumulate(a) >= y)
    {
        cout << 0 << '\n';
        return;
    }
    ll cha = y - accumulate(a);
    //    debug(cha);
    ranges::sort(a);
    // 最多一次魔法！
    for (int i = 0;i < 64;i++) //highest digit
    {
        vector<i128> b(n);
        for (int j = 0;j < n;j++)b[j] = a[j];
        vector<bool> xored(n);
        for (int j = 0;j < n;j++)
        {
            if ((b[j] & (1ULL << i)) == 0)
            {
                xored[j] = 1;
            }
        }
        vector<i128> ans(i + 1);
        for (int j = 0;j <= i;j++)
        {
            for (int k = 0;k < n;k++)
            {
                if (xored[k])
                {
                    ans[j] += (b[k] ^ (1ULL << j)) - b[k];
                }
            }
        }
        i128 cha2 = 0;
        u64 ansnum = 0;
        for (int j = 0;j <= i;j++)
            if (ans[j] > 0)
            {
                cha2 += ans[j];
                ansnum += (1ULL << j);
            }
        for (int j = i;j >= 0;j--)
        {
            if (ans[j] > 0 && cha2 - ans[j] >= cha)
            {
                cha2 -= ans[j];
                ansnum -= (1ULL << j);
            }
        }
        if (cha2 >= cha)
        {
            cout << ansnum << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; while (t--)
        solve(); return 0;
}