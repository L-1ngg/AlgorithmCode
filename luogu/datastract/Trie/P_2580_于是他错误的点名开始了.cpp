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

struct trie {
    int nex[N][26], cnt;
    int exist[N];
    int vis[N];

    void init() {
        memset(nex, 0, sizeof nex);
        memset(exist, 0, sizeof exist);
        memset(vis, 0, sizeof vis);
        cnt = 0;
    }

    void insert(std::string s)
    {
        int len = s.length();
        int p = 0;
        for (int i = 0; i < len;i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    void find(std::string s)
    {
        int len = s.length();
        int p = 0;
        for (int i = 0; i < len;i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c]) {
                std::cout << "WRONG\n"; return;
            }
            p = nex[p][c];
        }
        if (exist[p])
        {
            if (vis[p])
                std::cout << "REPEAT\n";
            else
            {
                vis[p] = 1;
                std::cout << "OK\n";
            }
        }
        else
            std::cout << "WRONG\n";
    }
};

trie t;
void solve()
{
    int n;  std::cin >> n;
    t.init();
    for (int i = 1; i <= n; i++)
    {
        std::string s;  std::cin >> s;
        t.insert(s);
    }
    int m;  std::cin >> m;
    for (int i = 1; i <= m;i++)
    {
        std::string s;  std::cin >> s;
        t.find(s);
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}