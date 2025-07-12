1. [A - Required Length](https://atcoder.jp/contests/abc411/tasks/abc411_a)

   基础题,判断一下给定的字符串长度即可

2. [B - Distance Table](https://atcoder.jp/contests/abc411/tasks/abc411_b)

   基础题,求一下前缀和数组,然后端点差分一下即可

3. [C - Black Intervals](https://atcoder.jp/contests/abc411/tasks/abc411_c)

   题目大意:给一个全0的数组,现在有一些操作,每次都将指定位置的1变0,0变1,输出每次操作之后,数组有几个连续的1段

   思路:思考什么情况下会发生段数的变化,即`i`两边的元素是一样的

~~~ cpp
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<int> a(n + 2);
    int ans = 0;
    while (q--) {
        int x;  std::cin >> x;
        if (a[x] == 0) {
            if (a[x - 1] == 0 && a[x + 1] == 0) ans++;
            if (a[x - 1] == 1 && a[x + 1] == 1) ans--;
        }
        else {
            if (a[x - 1] == 0 && a[x + 1] == 0) ans--;
            if (a[x - 1] == 1 && a[x + 1] == 1) ans++;
        }
        a[x] = 1 - a[x];
        std::cout << ans << '\n';
    }
}
~~~

4. [D - Conflict 2](https://atcoder.jp/contests/abc411/tasks/abc411_d)

   **题目大意**:字符串操作题,现在有q个查询,每个查询都会对一些数组进行字符串操作.

   **思路**:很容易想到可以直接模拟,但是仔细检查复杂度过后发现直接模拟的复杂度是无法通过的(因为复制字符串的复杂度是`O(n)`,因此可以采取一些`lazy`操作,对于1,3操作只改变指针,对于2操作,增加链表的长度

``` cpp
std::vector<int> a(N), fa(N + 1);
std::vector<std::string> s(N);

void dfs(int x) {
    if (!x) return;
    dfs(fa[x]);
    std::cout << s[x];
}

void solve()
{
    int n, q;   std::cin >> n >> q;
    int cnt = 0, now = 0;
    //1 a[x] = now
    //2 new {cnt++, -> x,a[x] == cnt}
    //3 now = a[x]
    while (q--) {
        int op, x;  std::cin >> op >> x;
        if (op == 1) a[x] = now;
        else if (op == 2) {
            std::cin >> s[++cnt];
            fa[cnt] = a[x];
            a[x] = cnt;
        }
        else now = a[x];
    }
    dfs(now);
    std::cout << '\n';
}
```

5. [E - E [max\]](https://atcoder.jp/contests/abc411/tasks/abc411_e)

**题目大意**:思维题,给`n`和骰子,并且给6个面赋值,然后所有骰子一直投掷,求最大值的期望

**思路**:可以把所有的值和相应的属于的骰子记录起来,然后反向排序,也就是枚举最大值,但是要注意在计算时,要先除掉自身骰子对概率的影响,操作完之后更新概率时,也要更新该骰子对概率的影响

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<a6> a(n + 1);
    std::vector<int> cnt(n + 1);

    std::vector<pii> v;
    for (int i = 1;i <= n;i++)
    {
        cnt[i] = 6;
        for (int j = 0;j < 6;j++)
        {
            std::cin >> a[i][j];
            v.push_back({ a[i][j],i });
        }
    }

    std::sort(v.rbegin(), v.rend());
    Z ans = 0, res = 1, div6 = qpow((Z)6, MOD[0] - 2);
    for (int i = 0;i < v.size();i++) {
        int p = v[i].second;
        Z tmp = res / (cnt[p] * div6);
        ans += tmp * div6 * v[i].first;

        res /= (cnt[p] * div6);
        cnt[p]--;
        res *= cnt[p] * div6;
    }
    std::cout << ans;
}
```

6. [F - Contraction](https://atcoder.jp/contests/abc411/tasks/abc411_f)

   **题目大意:**给定一个无向图和一些边,然后有q个询问,每次询问第i个边的两个端点是否属于一个集合,如果不属于,就要把两个点缩点,然后输出新图的边的条数

   **思路:**直接模拟,利用并查集判断两点是否属于一个集合,然后在缩点合并的时候要注意,使用启发式合并(根据集合的大小合并)来优化复杂度

```cpp

std::vector<int> fa;
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void solve()
{
    int n, m;   std::cin >> n >> m;
    fa.assign(n + 1, 0);
    std::iota(fa.begin(), fa.end(), 0);
    std::vector<std::set<int>> adj(n + 1);
    std::vector<pii> e(m + 1);

    for (int i = 1;i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        e[i].first = u, e[i].second = v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int q;  std::cin >> q;
    while (q--) {
        int id; std::cin >> id;
        auto [u, v] = e[id];
        u = find(u), v = find(v);
        if (u == v) {
            std::cout << m << "\n";
            continue;
        }
        int szu = adj[u].size(), szv = adj[v].size();
        if (szu < szv)   std::swap(u, v);
        for (auto to : adj[v]) {
            adj[to].erase(v);
            m--;
            if (to != u && !adj[u].count(to)) {
                adj[u].insert(to);
                adj[to].insert(u);
                m++;
            }
        }
        fa[v] = u;
        adj[v].clear();
        std::cout << m << "\n";
    }
}
```

