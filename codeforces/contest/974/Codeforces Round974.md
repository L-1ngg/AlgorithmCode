1. [Problem - A - Codeforces](https://codeforces.com/contest/2014/problem/A)

直接模拟即可

``` cpp
void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    int sum = 0;
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        if (a[i] >= k) sum += a[i];
        if (a[i] == 0 && sum) ans++, sum--;
    }
    std::cout << ans << '\n';
}
```

2. [Problem - B - Codeforces](https://codeforces.com/contest/2014/problem/B)

题目大意:有一颗树上,每天会长$i^i$个叶子,每个叶子会留k天,问最后一天的时候,树上的叶子数量是奇数还是偶数

思路:由于平方数的奇偶性并不会改变,因此只需要看最后k天里,奇数的个数

``` cpp
void solve()
{
    int n, k;   std::cin >> n >> k;
    if (((n + 1) / 2 - (n - k + 1) / 2) & 1)    std::cout << "NO\n";
    else std::cout << "YES\n";
}

```

3. [Problem - C - Codeforces](https://codeforces.com/contest/2014/problem/C)

题目大意:给定n个数字,现在可以给数字额外增加一定的值,问至少要加多少才能保证超过一半的数严格大于平均数的一半

思路:直接数学推公式

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    i64 sum = 0;
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (n <= 2) {
        std::cout << "-1\n";
        return;
    }
    std::sort(a.begin() + 1, a.end());
    int base = n / 2 + 1;
    i64 ans = n * 2ll * a[base] - sum;
    std::cout << std::max(0ll, ans + 1) << '\n';
}
```

4.[Problem - D - Codeforces](https://codeforces.com/contest/2014/problem/D)

题目大意:给定n天,然后有一系列的事情会覆盖`L~R`天,现在有mom和bro来访,希望bro来访期间,有最多的事情,mom来访期间有最少的事情

思路:看连续的k天里,有多少个事件,也可以转换成,看连续的k天里,没有多少事件,问题得以简化<br>一段时间不被事件包括的定义可以看出,时间的右端点小于事件的左端点,或者时间的左端点大于事件的右端点,因此可以有一个事件左端点的后缀数组和事件右端点的前缀数组

``` cpp

void solve()
{
    int n, d, k;    std::cin >> n >> d >> k;
    std::vector<int> L(n + 2), R(n + 2);
    for (int i = 1;i <= k;i++) {
        int l, r;   std::cin >> l >> r;
        L[l]++;
        R[r]++;
    }
    for (int i = 1;i <= n;i++) R[i] += R[i - 1];
    for (int i = n;i >= 0;i--) L[i] += L[i + 1];

    int mx = -inf, mn = inf, imx, imn;
    for (int i = 1;i + d - 1 <= n;i++)
    {
        int num = L[i + d] + R[i - 1];
        if (num > mx) mx = num, imx = i;
        if (num < mn) mn = num, imn = i;
    }
    std::cout << imn << " " << imx << '\n';
}

```

5. [Problem - E - Codeforces](https://codeforces.com/contest/2014/problem/E)

题目大意:从起点和终点都有一个人,他们俩之间要相遇,但是只可以在顶点处相遇,现在图不一定联通,并且图中的一些点有horse,这个人上马之后,后续的行进速度会乘以二,任何一方都可以选择在任何顶点等待,问两人相遇的最短时间是多少

思路:可以从起点和终点都分别跑一遍dij,但是由于horse的存在,有一些点是允许二次访问的,所以在传统的dij基础之上每一个点访问的时候的`vis[i]`换成`vis[i][2]`一个对应步行,一个骑马,就保证了一个点允许二次访问

``` cpp
void solve()
{
    int n, m, h;    std::cin >> n >> m >> h;
    std::vector adj(n + 1, std::vector<pii>());
    std::vector<int> v(n + 1);
    for (int i = 1;i <= h;i++) {
        int x;  std::cin >> x;
        v[x] = 1;
    }
    for (int i = 1;i <= m;i++) {
        int u, v, w;   std::cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }

    auto dij = [&](int root) {
        std::vector<i64> dis(n + 1, INF);
        std::vector<a2> vis(n + 1);

        dis[root] = 0;
        std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;
        pq.push({ 0,root,0 });

        while (pq.size()) {
            auto [d, u, st] = pq.top();
            pq.pop();
            if (v[u]) st = 1;
            if (vis[u][st])  continue;
            vis[u][st] = 1;

            for (auto [v, w] : adj[u]) {
                int t = (st == 1 ? w / 2 : w);
                if (d + t < dis[v]) {
                    dis[v] = d + t;
                }
                pq.push({ d + t,v,st });
            }
        }
        return dis;
        };

    auto dis1 = dij(1), dis2 = dij(n);
    i64 ans = INF;
    for (int i = 1;i <= n;i++)
        ans = std::min(ans, std::max(dis1[i], dis2[i]));
    std::cout << (ans == INF ? -1 : ans) << '\n';
}
```

6. [Problem - F - Codeforces](https://codeforces.com/contest/2014/problem/F)

题目大意:有一个树形结构,每个点都有一定数量的黄金,现在可以选择一些节点进行保护,保护的要求是,从该节点的所有相邻节点里分别抽取c个黄金,节点的黄金可以为负数,问最终最多可以有多少黄金被保护

思路:树形结构,相邻状态约束,无后束约束,因此考虑树形dp

``` cpp
void solve()
{
    int n, c;   std::cin >> n >> c;
    std::vector adj(n + 1, std::vector<int>());
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    adj[0].push_back(1);
    std::vector<a2> f(n + 1);
    auto dfs = [&](auto&& self, int u, int fa)->void {
        f[u][1] = a[u];
        for (auto v : adj[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            f[u][0] += std::max(f[v][1], f[v][0]);
            f[u][1] += std::max(f[v][1] - 2 * c, f[v][0]);
        }
        };
    dfs(dfs, 1, 0);
    // std::cout << f[1][0] << '\n';
    std::cout << std::max(f[1][1], f[1][0]) << '\n';
}
```

7. [Problem - G - Codeforces](https://codeforces.com/contest/2014/problem/G)

题目大意:一些牛奶会在特定的天送来特定的数量,每个牛奶的保质期是一定的k天,每次喝牛奶的时候,必须先喝最新鲜的,再喝次新鲜的.如果当天剩余可食用的牛奶数量大于等于m,则会喝掉m单位牛奶,并且心情满意,否则会喝掉剩余全部牛奶但心情不会愉悦,现在要求计算出会有多少天愉悦

思路:考虑模拟,用vector模拟栈来解决先喝最新鲜的问题,若当前最新鲜牛奶数量大于等于m,可以快速计算能喝到哪一天,优化模拟过程,否则只能暴力满足m,具体模拟需要注意到的细节根据代码<br>例如:牛奶到哪一天会过期,牛奶最多能喝到哪一天

``` cpp

void solve()
{
    int n, m, k;    std::cin >> n >> m >> k;

    std::vector<pii> v;
    int ans = 0;
    int cur = 0;
    auto work = [&](int d) {
        while (v.size() && cur < d) {
            auto& [x, a] = v.back();
            if (cur > x + k - 1) {
                v.clear();
                continue;
            }
            if (a >= m)
            {
                int r = std::min({ d - 1, cur + a / m - 1 , x + k - 1 });
                ans += r - cur + 1;
                a -= (r - cur + 1) * m;
                cur = r + 1;
                continue;
            }
            int need = m;
            while (v.size() && need) {
                auto& [x, a] = v.back();
                if (cur > x + k - 1) {
                    v.clear();
                    continue;
                }
                if (a <= need) {
                    need -= a;
                    v.pop_back();
                }
                else {
                    a -= need;
                    need = 0;
                }
            }
            if (need == 0) ans++;
            cur++;
        }
        cur = d;
        };

    for (int i = 1;i <= n;i++)
    {
        int d, a;   std::cin >> d >> a;
        work(d);
        v.push_back({ d,a });
    }
    work(1e8);
    std::cout << ans << '\n';
}
```

8. [Problem - H - Codeforces](https://codeforces.com/contest/2014/problem/H)

题目大意:A先手,B后手,游戏规则是一人选一个,轮换选择,选完为止,谁的值大谁就获胜了,现在为了让B不输掉比赛,截取一定的范围内选择,给定一些范围,判断B能否不输掉比赛

思路:首先可以注意到,B无法获胜,因此要想B不输,必须得让B的分数等于A的分数,要想这样,就得要求区间当中所有出现的数字都是偶数次出现<br>区间中的数偶数次出现,可以考虑使用前缀异或和/莫队,这里先给出前缀异或和的实现方法

``` cpp
std::vector<u64> h(N + 1);
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<u64> pre(n + 1);
    for (int i = 1;i <= n;i++) {
        u64 x;  std::cin >> x;
        pre[i] ^= pre[i - 1] ^ h[x];
    }
    while (q--) {
        int l, r;   std::cin >> l >> r;
        std::cout << ((pre[r] == pre[l - 1]) ? "YES\n" : "NO\n");
    }
}
std::mt19937_64 rnd(time(0));
    for (int i = 1;i <= N;i++) {
        h[i] = rnd();
    }
```

增加一个莫队写法

``` cpp
std::vector<int> cnt(MAXN);
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        cnt[a[i]] = 0;
    }

    std::vector<a3> que(q + 1);
    for (int i = 1;i <= q;i++) {
        int l, r;
        std::cin >> l >> r;
        que[i] = { l,r,i };
    }
    int Knum = n / std::min<int>(n, sqrt(q));
    std::vector<int> K(n + 1);
    for (int i = 1; i <= n; i++) {
        K[i] = (i - 1) / Knum + 1;
    }
    std::sort(que.begin() + 1, que.end(), [&](auto x, auto y) {
        if (K[x[0]] != K[y[0]]) return x[0] < y[0];
        if (K[x[0]] & 1) return x[1] < y[1];
        return x[1] > y[1];
        });

    int l = 1, r = 0, val = 0;
    std::vector<int> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        auto [ql, qr, id] = que[i];
        auto add = [&](int x) -> void {
            cnt[x] ^= 1;
            if (cnt[x]) val++;
            else val--;
            };
        // auto del = [&](int x) -> void {};
        while (l > ql) add(a[--l]);
        while (r < qr) add(a[++r]);
        while (l < ql) add(a[l++]);
        while (r > qr) add(a[r--]);
        ans[id] = val;
    }
    for (int i = 1;i <= q;i++)
        std::cout << (ans[i] == 0 ? "YES\n" : "NO\n");
}
```

