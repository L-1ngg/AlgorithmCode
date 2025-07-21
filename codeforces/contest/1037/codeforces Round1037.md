1. [Problem - A - Codeforces](https://codeforces.com/contest/2126/problem/A)

题目大意:给定一个十进制数n,找出每个数位当中最小的那个

思路:直接模拟即可

``` cpp
void solve()
{
    int n;  std::cin >> n;
    int ans = 10;
    while (n)
    {
        ans = std::min(ans, n % 10);
        n /= 10;
    }
    std::cout << ans << '\n';
}
```

2. [Problem - B - Codeforces](https://codeforces.com/contest/2126/problem/B)

题目大意:外出旅行要求未来的`k`天都是晴天,并且每次外出之后要休息一天才能继续外出,现在给定一系列的天气,问最多可以外出多少次

思路:每个连续的好天气和之后的一天可以当作一组用于计算

``` cpp
void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int>  a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    int cnt = 0, lst = 1;
    for (int i = 1;i <= n;i++) {
        if (a[lst] != a[i])
        {
            if (a[lst] == 0) cnt += (i - lst + 1) / (k + 1);
            lst = i;
        }
        if (a[i] == 0 && i == n) {
            cnt += (i - lst + 2) / (k + 1);
        }
    }
    std::cout << cnt << '\n';
}

```

3. [Problem - C - Codeforces](https://codeforces.com/contest/2126/problem/C)

题目大意:初始有一个随机的高度,每上一个高度都有一定的准备时间,除此之外水位线的上升速度是1m/s,问能否在不被淹的情况下上到最高点

思路:模拟一下水位线的上升 判断水位线和此时的高度的相对关系即可

``` cpp
void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    int x = a[k];
    std::sort(a.begin() + 1, a.end());
    for (int i = 1;i <= n;i++) if (a[i] == x) { x = i; break; }

    std::vector<int> d(n + 1);
    for (int i = 1;i <= n;i++) d[i] = a[i] - a[i - 1];
    int h = 0;
    for (int i = x;i <= n - 1;i++) {
        h += d[i + 1];
        if (h > a[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}
```

4. [Problem - D - Codeforces](https://codeforces.com/contest/2126/problem/D)

题目大意:有一系列的区间和值,如果此时的值落在区间内,就会变成目标值,问最终最大能有多大

思路:排序之后,直接模拟即可,取一个max

``` cpp
void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector<a3> a(n + 1);
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < 3;j++)
            std::cin >> a[i][j];

    int ans = k;
    std::sort(a.begin() + 1, a.end());
    for (int i = 1;i <= n;i++) {
        if (ans < a[i][0]) break;
        if (ans > a[i][1]) continue;
        ans = std::max(ans, a[i][2]);
    }
    std::cout << ans << '\n';
}
```

5. https://codeforces.com/contest/2126/problem/E

题目大意:现在有两个数组,一个是前缀gcd数组,一个是后缀gcd数组,问能否构造出一个序列,满足这两个数组

思路:根据数组和gcd的特点判断

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> pre(n + 1);
    std::vector<int> suf(n + 1);
    for (int i = 1;i <= n;i++)  std::cin >> pre[i];
    for (int i = 1;i <= n;i++)  std::cin >> suf[i];

    for (int i = 1;i <= n - 1;i++)
        if (pre[i] % pre[i + 1] != 0) {
            std::cout << "NO\n";
            return;
        }
    for (int i = n;i >= 1 + 1;i--)
        if (suf[i] % suf[i - 1] != 0) {
            std::cout << "NO\n";
            return;
        }
    if (pre[n] != suf[1]) {
        std::cout << "NO\n";
        return;
    }
    for (int i = 1;i <= n - 1;i++)
        if (std::gcd(pre[i], suf[i + 1]) != pre[n]) {
            std::cout << "NO\n";
            return;
        }
    std::cout << "YES\n";
}
```

6. [Problem - F - Codeforces](https://codeforces.com/contest/2126/problem/F)

题目大意:有一棵树,和一些有权边,每个节点都有一个初始颜色,如果两个节点之间有边并且俩节点之间的颜色不同,则视为这棵树拥有这个边的权值.现在有q次操作,每次操作选定一个点然后修改他的颜色,并且询问修改之后树的总权值是多少

思路:很容易想到对每一个点都有一个map记录邻近的点里,不同的颜色对应的权值之和.当修改某一个点之后,应该把总值减去 改之后颜色的对应总权值 ,然后加上改之前颜色的对应总权值.除此之外,要处理邻近的点里因为此点改颜色对应的影响.<br>但是注意到数据规模较大,如果每个修改都要去通知相应的点处理的话,复杂度为$n^{2}$,不符合要求,于是我们想到度数较大的点不多,我们可以使用lazy的思想去优化,给每一个点定义两个数组,一个upd,一个con,前者为当前点的邻点中修改了值的点,后者为当前点处理之后需要通知的邻近的点

``` cpp
void solve() {
    int n, q;   std::cin >> n >> q;
    std::vector<int> col(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> col[i];
    std::map<int, pii> adj[n + 1];
    std::map<int, i64> res[n + 1];
    std::vector<int> upd[n + 1];
    std::vector<int> con[n + 1];

    i64 ans = 0;
    // std::cout << res[2][1] << '\n';
    for (int i = 1;i <= n - 1;i++) {
        int u, v, w;    std::cin >> u >> v >> w;
        adj[u][v] = { w,col[v] };
        adj[v][u] = { w,col[u] };

        if (col[u] != col[v])   ans += w;
        res[u][col[v]] += w;
        res[v][col[u]] += w;

        con[v].push_back(u);
        con[u].push_back(v);
    }

    while (q--) {
        int u, y;   std::cin >> u >> y;

        if (upd[u].size()) {
            for (auto v : upd[u])
            {
                int tmpcol = adj[u][v].second;
                adj[u][v].second = col[v];
                if (tmpcol != col[v]) {
                    if (!(res[u][tmpcol] -= adj[u][v].first)) res[u].erase(tmpcol);
                    res[u][col[v]] += adj[u][v].first;
                }

                con[v].push_back(u);
            }
        }
        upd[u].clear();

        for (auto v : con[u])
            upd[v].push_back(u);
        con[u].clear();

        ans -= res[u][y];
        ans += res[u][col[u]];
        col[u] = y;
        std::cout << ans << '\n';
    }
}
```

7. [Problem - G1 - Codeforces](https://codeforces.com/contest/2126/problem/G1)

题目大意:给定一个数组,在数组当中截取一个连续的子数组,使得`med-min`值最大,其中`med`是排序之后的中位数

思路:注意到`a[i]`较小,意味着`med`的值不会超过100,因此可以枚举`med`的值,然后再枚举每一项`a[i]`令其作为最小值,判断是否有一个包括`a[i]`的区间的中位数至少为枚举的`med`<br>tips:判断某一个区间的中位数的方法,用一个辅助数组b,`b[j] = (a[j] >= i ? 1 : -1);`然后取b数组的前缀和,若某个区间的和>=0,则意味者该段区间的中位数大于等于`med`<br>因此问题转化为枚举一个i,如何快速判断有一个区间包括i,并且区间的和大于等于0,可以借助premn和sufmx数组来判断,通过比较pre[i]和premn[i-1]的值,若在此之前存在一个位置的pre较小,则表明这个区间的和一定大于等于0,或者通过比较pre[i-1]和sufmx[i],若在此之后存在一个位置的pre较大,则表明这个区间和一定大于等于0,然后把答案统计一下取个max

``` cpp
void solve()
{
    int n;  std::cin >> n;
    int mx = std::min(n, 100);
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];

    int ans = 0;
    for (int i = 1;i <= mx;i++) {
        std::vector<int> b(n + 1);
        for (int j = 1;j <= n;j++) b[j] = (a[j] >= i ? 1 : -1);
        std::vector<int> pre(n + 1);
        for (int j = 1;j <= n;j++) pre[j] = pre[j - 1] + b[j];

        std::vector<int> premn(n + 1), sufmx(n + 1);
        premn[0] = 0, sufmx[n] = pre[n];
        for (int j = 1;j <= n;j++)
            premn[j] = std::min(premn[j - 1], pre[j]);
        for (int j = n - 1;j >= 1;j--)
            sufmx[j] = std::max(sufmx[j + 1], pre[j]);

        for (int j = 1;j <= n;j++)
            if (premn[j - 1] <= pre[j] || pre[j - 1] <= sufmx[j])
                ans = std::max(ans, i - a[j]);
    }
    std::cout << ans << '\n';
}

```

