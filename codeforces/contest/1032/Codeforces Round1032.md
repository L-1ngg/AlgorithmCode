1. [Problem - A - Codeforces](https://codeforces.com/contest/2121/problem/A)

题目大意:给定一个区间和一个初始点,要求走完区间全程,问最少要走多远

思路:直接贪心,先到更近的端点,再走全程

``` cpp
void solve()
{
    int n, p;  std::cin >> n >> p;
    int mn = inf, mx = 0;
    while (n--) {
        int x;  std::cin >> x;
        mn = std::min(mn, x);
        mx = std::max(mx, x);
    }
    std::cout << std::min(std::abs(mn - p), std::abs(mx - p)) + mx - mn << '\n';
}
```

2. [Problem - B - Codeforces](https://codeforces.com/contest/2121/problem/B)

题目大意:给定一个字符串,问该字符串能否写成`A + B + C`的形式,其中`B`为`A + C`的子串

思路:只需要判定某个字符在之前或者之后有没有出现过即可

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    std::vector<int> cnt(26, 0);
    cnt[s[0] - 'a']++;
    cnt[s[n - 1] - 'a']++;
    for (int i = 1;i < n - 1;i++)
    {
        if (cnt[s[i] - 'a']++) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
}
```

3. https://codeforces.com/contest/2121/problem/C

题目大意:给定一个矩阵,现在可以找一个十字线,把十字线上的数字都减一,问操作之后,矩阵当中元素的最大值最小能为多少

思路:只需要判断该十字线能否覆盖所有的mx即可,矩阵中点和线的经典操作方式是,维护一个行数组和列数组

``` cpp
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector a(n + 1, std::vector<int>(m + 1));
    int mx = 0, cnt = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] > mx)  mx = a[i][j], cnt = 1;
            else if (a[i][j] == mx) cnt++;
        }

    std::vector<int> r(n + 1), c(m + 1);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (a[i][j] == mx)
                r[i]++, c[j]++;

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (r[i] + c[j] - (a[i][j] == mx) == cnt)
            {
                std::cout << mx - 1;
                return;
            }
    std::cout << mx;
}
```

4. [Problem - D - Codeforces](https://codeforces.com/contest/2121/problem/D)

题目大意:给定两个数组,要求每个数组是递增的,并且对于每个`i`,都有`a[i] < b[i]`,问要操作多少次,该如何操作

思路:直接冒泡排序即可

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    for (int i = 1;i <= n;i++)   std::cin >> b[i];

    std::vector<pii> ans;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n - i;j++)
        {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                ans.push_back({ 1, j });
            }
            if (b[j] > b[j + 1]) {
                std::swap(b[j], b[j + 1]);
                ans.push_back({ 2, j });
            }
        }

    for (int i = 1;i <= n;i++)
        if (a[i] > b[i])
            ans.push_back({ 3,i });

    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans) std::cout << x << " " << y << '\n';
}
```

5. [Problem - E - Codeforces](https://codeforces.com/contest/2121/problem/E)

题目大意:给两个数字`l,r`,要求构造一个数字,使得数字`x`满足`l <= x <= r`,并且数位上相同的数量最少

思路:可以从高位开始取数字`x = x * 10 + a[i];`.注意到,若此时数字之间的差大于等于2,则后续一定可以不一样,因此按照该思路直接模拟即可

``` cpp
void solve()
{
    int l, r;   std::cin >> l >> r;
    std::vector<int> a, b;
    while (l) {
        a.push_back(l % 10);
        l /= 10;
        b.push_back(r % 10);
        r /= 10;
    }
    int n = a.size();
    n--;

    int ans = 0;
    int x = 0, y = 0;
    for (int i = n;i >= 0;i--) {
        x = x * 10 + a[i];
        y = y * 10 + b[i];
        if (x == y) ans += 2;
        else if (std::abs(x - y) == 1) ans += 1;
        else break;
    }
    std::cout << ans << '\n';
}
```

6. https://codeforces.com/contest/2121/problem/F

题目大意:给定一个数组a,和整数`s,x`要求找到数组当中的子线段,满足子线段的和为s,并且子线段当中的元素的max为x,问有多少个这样的线段

思路:对于这种要求一个区间的和为s的题,常见的处理方式是用一个map存储数组的前缀和.`pre[i]-pre[j]`的和为`s`,可以通过map很快的找到,但是该题还有一个max为x的限制,只需要判断 当前元素如果大于x,把之前的全部清零即可

``` cpp
void solve()
{
    int n;  std::cin >> n;
    i64 s, x;   std::cin >> s >> x;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)  std::cin >> a[i];
    std::vector<i64> pre(n + 1);
    for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];

    auto cal = [&](int x) {
        std::map<int, int> cnt;
        cnt[0] = 1;
        i64 ans = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i] > x) cnt.clear();
            ans += cnt[pre[i] - s];
            cnt[pre[i]]++;
        }
        return ans;
        };

    std::cout << cal(x) - cal(x - 1) << '\n';
}
```

7. [Problem - G - Codeforces](https://codeforces.com/contest/2121/problem/G)

题目大意:给定一个二进制串s,并且定义一个`f[p]`为二进制串p当中,出现次数最多的字符的个数,要求求出二进制串s的全部字串p的`f[p]`之和

思路:考虑每个字符对`f[p]`的贡献,注意到若当前元素加入到一个新子串之后,产生贡献的原因是因为原子串中,`cnt1 >= cnt0 (cnt0 >= cnt1)`,因此新元素加入到原子串末尾之后,产生的贡献是原子串的贡献+因为该元素导致的额外的贡献.考虑用树状数组维护一个`cnt0-cnt1`,若新加入一个`0`,则意味着坐标零点要左移,并且(cnt0 - cnt1 == 1)的个数要+1,若新加入`1`,分析方式同理

``` cpp
struct BIT {
    std::vector<i64> w;
    int n;
    BIT(int n) : n(n), w(n + 1) {}
    void add(int x, i64 v) {
        for (; x <= n; x += x & -x) {
            w[x] += v;
        }
    }
    i64 rangeAsk(int l, int r) { // 差分实现区间和查询
        auto ask = [&](int x) {
            i64 ans = 0;
            for (; x; x -= x & -x) {
                ans += w[x];
            }
            return ans;
            };
        return ask(r) - ask(l - 1);
    }
};

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;

    int m = 2 * n + 20;
    BIT tr(m + 1);
    int zero = n + 10;
    i64 ans = 0, res = 0;

    for (auto c : s) {
        if (c == '1') {
            res += tr.rangeAsk(1, zero);
            res++;
            zero++;
            tr.add(zero - 1, 1);
        }
        else {
            res += tr.rangeAsk(zero, m);
            res++;
            zero--;
            tr.add(zero + 1, 1);
        }
        ans += res;
    }
    std::cout << ans << '\n';
}
```

8. [Problem - H - Codeforces](https://codeforces.com/contest/2121/problem/H)

题目大意:LIS,但是每次给定的是一个区间,要求求出所有前缀长度的LIS

思路:仿照LIS的原理

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::multiset<int> st;

    while (n--) {
        int l, r;   std::cin >> l >> r;
        auto it = st.upper_bound(r);
        if (it != st.end()) st.erase(it);
        st.insert(l);
        std::cout << st.size() << " ";
    }
    std::cout << '\n';
}
```





