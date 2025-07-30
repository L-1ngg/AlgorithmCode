1. [Problem - A - Codeforces](https://codeforces.com/contest/2008/problem/A)

题目大意:给x个1和y个2,要求在这些数字之前加上正负符号,使得最终的结果为0

思路:优先把2消掉,然后再消掉1

``` cpp
void solve()
{
    int a, b;   std::cin >> a >> b;
    b = b % 2;
    if (b && a < 2) {
        std::cout << "NO\n";
        return;
    }
    a -= (b == 1 ? 2 : 0);
    std::cout << ((a & 1) ? "NO\n" : "YES\n");
}
```

2. https://codeforces.com/contest/2008/problem/B

题目大意:给定一个字符串,让字符串顺序按照规则摆放,问最终能否摆放成满足要求的正方形

思路:直接模拟即可

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = " " + s;
    int sz = std::sqrt(n);
    if (sz * sz != n) {
        std::cout << "No\n";
        return;
    }
    for (int i = 1;i <= sz;i++)
        for (int j = 1;j <= sz;j++)
        {
            int f = 0;
            if (i == 1 || i == sz || j == 1 || j == sz) f = 1;
            if (s[(i - 1) * sz + j] - '0' != f) {
                std::cout << "No\n";
                return;
            }
        }
    std::cout << "Yes\n";
}
```

3. [Problem - C - Codeforces](https://codeforces.com/contest/2008/problem/C)

题目大意:给定一个区间范围`L-R`,要求构造一个数组,数组当中每个元素都要在该区间当中,并且元素之间的差值要逐渐增大,问最多能构造多少个数字的数组

思路:可以构造第二个比第一个大一,第三个比第二个大二,第四个比第三个大3,因此可以快速求出第n个元素的大小,根据单调性,可以使用二分答案

``` cpp
void solve()
{
    i64 l, r;   std::cin >> l >> r;

    i64 L = 1, R = r - l + 1, ans = 0;

    auto check = [&](i64 x) {
        return l + (1 + x) * x / 2 <= r;
        };
    while (L <= R) {
        i64 mid = L + R >> 1;
        if (check(mid)) L = mid + 1, ans = mid;
        else R = mid - 1;
    }
    std::cout << ans + 1 << '\n';
}
```

4. [Problem - D - Codeforces](https://codeforces.com/contest/2008/problem/D)

题目大意:有一个排列,但是是打乱的,现在有一个行动规则`i = p[i]`,所有能互相抵达的点视为一体,现在有一个初始序列,意味着每个地方是黑色或者白色,并且每个位置可以管控当前位置的黑色,视为一体的也可以相互管控,问每个位置能管控的最多的黑色元素是多少个

思路:通过并查集来维护每个元素管理的元素个数,但是细节比较复杂

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::vector<int> p(n + 1), f(n + 1);
    std::vector<int> ans(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> p[i];
    std::string s;  std::cin >> s;
    s = " " + s;
    for (int i = 1;i <= n;i++) if (s[i] == '0') ans[i]++;
    std::iota(f.begin(), f.end(), 0);
    auto find = [&](auto&& self, int x)->int {
        return f[x] = (f[x] == x ? x : self(self, f[x]));
        };

    for (int i = 1;i <= n;i++)
    {
        int x = find(find, i), y = find(find, p[i]);
        if (x == y) continue;
        ans[x] += ans[y];
        f[y] = x;
    }
    for (int i = 1;i <= n;i++)
    {
        int x = find(find, i);
        std::cout << ans[x] << " \n"[i == n];
    }
}
```

5. https://codeforces.com/contest/2008/problem/E

题目大意:给定一个初始字符串,要求把初始字符串变成一个好串<br>好串的定义:所有的奇数下标都是同一个字符,所有的偶数下表也都是同一个字符,并且最终字符串的长度是偶数<br>有两种方式变换初始字符串: 1.删除字符串中的一个元素(但只能删除一个) 2.把字符串当中的某个位置的颜色改成其他颜色<br>现在要求求最少需要多少次操作使得初始字符串变成一个好串

思路:若初始原本就是偶数长度,则不能进行操作一,因此只需要看奇数位和偶数位上,相同元素最多的有多少个;若初始长度是奇数,则可以枚举删除的位置,然后通过前缀和后缀和快速判断此时最多的元素的个数

``` cpp
void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = " " + s;
    std::vector<std::vector<int>> suf(n + 3, std::vector<int>(26));
    for (int i = n;i >= 1;i--)
    {
        for (int j = 0;j < 26;j++)
            suf[i][j] += suf[i + 2][j];
        suf[i][s[i] - 'a']++;
    }
    if (n % 2 == 0)
    {
        int ans = 0;
        int mx = 0;
        for (int i = 0;i < 26;i++)
            mx = std::max(mx, suf[1][i]);
        ans += n / 2 - mx;
        mx = 0;
        for (int i = 0;i < 26;i++)
            mx = std::max(mx, suf[2][i]);
        ans += n / 2 - mx;
        std::cout << ans << '\n';
        return;
    }

    std::vector<a2> cnt(26);
    int ans = inf;
    for (int i = 1;i <= n;i++)
    {
        int res = 0;
        int mx = 0;
        for (int j = 0;j < 26;j++)
            mx = std::max(mx, cnt[j][0] + suf[i + (i & 1 ? 2 : 1)][j]);
        // std::cout << mx << '\n';
        res += n / 2 - mx;
        mx = 0;
        for (int j = 0;j < 26;j++)
            mx = std::max(mx, cnt[j][1] + suf[i + (i & 1 ? 1 : 2)][j]);
        res += n / 2 - mx;
        // std::cout << mx << '\n';
        ans = std::min(ans, res);
        cnt[s[i] - 'a'][i & 1]++;
    }
    std::cout << ans + 1 << '\n';
}
```

