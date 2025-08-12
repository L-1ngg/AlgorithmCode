1. [Problem - A - Codeforces](https://codeforces.com/contest/1923/problem/A)

题目大意:有一个序列,要求序列当中的1是在一个连通块的,可以对初始的序列进行交换的操作,问做少需要多少次操作

思路:只需要看第一个1和最后一个1中间有多少个0即可

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)  std::cin >> a[i];
    int st = -1, en = -1;
    int res = 0;
    int ans;
    for (int i = 1;i <= n;i++)
    {
        if (st == -1 && a[i]) st = i;
        if (a[i]) en = i, ans = res;
        if (st != -1 && !a[i]) res++;
    }
    std::cout << ans;
}
```

2. [Problem - B - Codeforces](https://codeforces.com/contest/1923/problem/B)

题目大意:有一些怪物在数轴上的点,每个怪物都有一个初始血量,并且每秒都会向原点0靠近一个单位,每秒我们都可以发射k个子弹,每个子弹造成的伤害是1,问能在杀死所有 n 个怪物的同时，不让任何一个怪物靠近你的角色吗？

思路:注意到怪物的分布`-n <= xi <= n`,也就是怪物的分布是有限的,可以用一个前缀数组,判断当前能造成的伤害和前缀数组的数值比较一下

``` cpp
void solve()
{
    i64 n, k;   std::cin >> n >> k;
    std::vector<i64> a(n + 1);
    std::vector<i64> b(n + 1);
    for (int i = 1;i <= n;i++)  std::cin >> b[i];
    for (int i = 1;i <= n;i++) {
        int p;  std::cin >> p;
        if (p < 0) p = -p;
        a[p] += b[i];
    }
    for (int i = 1;i <= n;i++) a[i] += a[i - 1];
    for (int i = 1;i <= n;i++)
        if (i * k < a[i])
        {
            std::cout << "NO";
            return;
        }
    std::cout << "YES";
}

```

3. [Problem - C - Codeforces](https://codeforces.com/contest/1923/problem/C)

题目大意:给定一个初始数组,并且有q次询问,每次询问`l`和`r`之间能否重新构造一个数组b,使得数组之和等于原区间和,并且满足`a[i] != b[i]`,如果可以构造,输出yes,否则输出no

思路:由观察容易发现,a[i]=1是特殊,所有`a[i]=1`的位置都要至少改成2,其余的位置最小可以改成1,因此只需要看区间和大小与cnt1 * 2 + !cnt1即可

``` cpp
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<i64> a(n + 1), cnt(n + 1);
    for (int i = 1;i <= n;i++) {
        std::cin >> a[i];
        if (a[i] == 1) cnt[i]++;
    }

    for (int i = 1;i <= n;i++)
        a[i] += a[i - 1], cnt[i] += cnt[i - 1];

    while (q--) {
        int l, r;   std::cin >> l >> r;
        if (l == r) {
            std::cout << "NO\n";
            continue;
        }
        i64 sum = a[r] - a[l - 1];
        int num = cnt[r] - cnt[l - 1];
        if (num * 2 + (r - l + 1 - num) > sum) std::cout << "NO\n";
        else std::cout << "YES\n";
    }
}
```

4. [Problem - D - Codeforces](https://codeforces.com/contest/1923/problem/D)

题目大意:有 n 个史莱姆排成一行。这些史莱姆从左到右依次编号为 1 到 n 。第 i 个黏液的大小是 ai,现在每个史莱姆可以吃掉周围比自己小的史莱姆,并且a[i]会增长被吃掉的单位.现在对于每一个史莱姆,计算这个史莱姆最早在多少s的时候会被吃掉,如果永远不会被吃掉,则输出-1

思路:首先,如果某个史莱姆小于相邻的二者其中之一的话,那么该史莱姆的答案一定是1<br>其余可以这样分析:1.在该位置的之前有一段区间和大于该元素 2.在该位置的之后有一段区间和大于该元素.这二者可以利用前缀和求解.其次需要注意一个问题,即使左边(右边)存在某一个区间之和大于该元素,如果这个区间内所有元素都相等,也是无法满足要求的(因为不能互相吃)<br>因此需要维护一个前缀和数组,一个后缀和数组,还需要维护 数组nl,nr,用于表示某元素左边(右边)第一个不相同的元素的位置

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    std::vector<i64> l(n + 1), r(n + 1);
    std::vector<i64> nl(n + 1), nr(n + 2);
    for (int i = 1;i <= n;i++) r[i] = r[i - 1] + a[i];
    for (int i = 1;i <= n;i++) l[i] = l[i - 1] + a[n - i + 1];

    nl[1] = 0;
    for (int i = 2;i <= n;i++)
    {
        if (a[i] != a[i - 1]) nl[i] = i - 1;
        else nl[i] = nl[i - 1];
    }
    nr[n] = nr[n + 1] = n + 1;
    for (int i = n - 1;i >= 1;i--)
    {
        if (a[i] != a[i + 1]) nr[i] = i + 1;
        else nr[i] = nr[i + 1];
    }

    std::vector<int> ans(n + 1, 0);
    for (int i = 1;i <= n;i++) {
        if (i > 1 && a[i] < a[i - 1]) { ans[i] = 1; continue; }
        if (i < n && a[i] < a[i + 1]) { ans[i] = 1; continue; }

        if (nl[i - 1] == 0 && nr[i + 1] == n + 1) { ans[i] = -1; continue; }

        int res = n + 1;
        if (nl[i - 1] != 0) {
            int L = n - nl[i - 1] + 1, R = n;
            while (L <= R) {
                int mid = L + R >> 1;
                if (l[mid] > l[n - i + 1] + a[i]) res = std::min(res, mid - (n - i + 1)), R = mid - 1;
                else L = mid + 1;
            }
        }
        if (nr[i + 1] != n + 1) {
            int L = nr[i + 1], R = n;
            while (L <= R) {
                int mid = L + R >> 1;
                if (r[mid] > r[i] + a[i]) res = std::min(res, mid - i), R = mid - 1;
                else L = mid + 1;
            }
        }
        if (res == n + 1) ans[i] = -1;
        else ans[i] = res;
    }
    for (int i = 1;i <= n;i++)   std::cout << ans[i] << " ";
}
```

5. https://codeforces.com/contest/1923/problem/E

题目大意:有一棵树,每个节点都有某种颜色,寻找树中美丽路径的条数<br>美丽路径:至少有两个节点,首尾的颜色相同,中间的点不得与首的颜色相同

思路:由分析可以知道,只需要找相邻的相同颜色点,然后统计一下即可,具体维护是一个比较典型的启发式合并,但是要注意如果不同子树当中颜色数是可以叠加的,因此要用map维护,具体见代码

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)    std::cin >> a[i];

    std::vector<std::map<int, int>> b(n + 1);
    std::vector adj(n + 1, std::vector<int>());
    for (int i = 1;i <= n - 1;i++)
    {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    i64 ans = 0;
    auto dfs = [&](auto&& self, int u, int fa)->void {
        for (auto v : adj[u])
        {
            if (v == fa)    continue;
            self(self, v, u);
            if (b[v].count(a[u])) ans += b[v][a[u]];

            if (b[v].size() > b[u].size()) std::swap(b[u], b[v]);
            for (auto [x, y] : b[v])
            {
                if (b[u].count(x) && a[u] != x) ans += (i64)y * b[u][x];
                b[u][x] += y;
            }
        }
        b[u][a[u]] = 1;
        };
    dfs(dfs, 1, 1);
    std::cout << ans;
}
```

