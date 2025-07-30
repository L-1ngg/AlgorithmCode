1.[Problem - A - Codeforces](https://codeforces.com/contest/2043/problem/A)

题目大意:有一个初始硬币,并且给定值,若此时硬币的价格大于3,则可以将硬币一分为二,每一份价值n/4

思路:直接模拟

``` cpp
void solve()
{
    i64 n;  std::cin >> n;
    i64 ans = 1;
    while (n > 3) {
        n /= 4;
        ans *= 2;
    }
    std::cout << ans << '\n';
}
```

2. [Problem - B - Codeforces](https://codeforces.com/contest/2043/problem/B)

题目大意:有两个数字`n`和`d`,构造一个数`n!`个d(dddddd....)问这样的数字能否被1,3,5,7,9整除?

思路:1是一定可以的<br>		3可以发现,若n>=3,则数位之和一定是3的倍数,其余情况暴力判断数位之和是否是三的倍数即可;对于5而言,要求最后一位必须是0或者5,对于7而言,发现111111可以被7整除,则只要n>=3,也可以被7整除,对于其他情况暴力判断;9和3同理

``` cpp
void solve()
{
    int n, d;   std::cin >> n >> d;
    std::cout << 1 << " ";
    if (n >= 3)  std::cout << 3 << " ";
    else std::cout << (n * d % 3 == 0 ? "3 " : "");
    if (d == 5)  std::cout << 5 << " ";
    if (n >= 3)  std::cout << 7 << " ";
    else if ((d * 10 + d) % 7 == 0)   std::cout << 7 << " ";
    if (n >= 6)  std::cout << 9 << " ";
    else {
        int num = 1;
        while (n) {
            num *= n--;
        }
        std::cout << (num * d % 9 == 0 ? "9 " : "");
    }
}
```

3. [Problem - C - Codeforces](https://codeforces.com/contest/2043/problem/C)

题目大意:有一段数组,其中最多有一个数不是-1或者1,问从数组当中截取子串,子串的取值范围有多少种,并且按顺序输出各种取值

思路:首先注意到一个特性:若一个区间全是1和-1,有区间和最大mx和区间和最小mn,则最终一定可以取到的范围是[mn,mx],区间最大最小值则可以通过dp来确定<br>根据只有一个的特性,想到可以根据这个数,把数组一分为二,然后先根据上述的dp来确定mx和mn,因此[mn,mx]之间的值都可以取到<br>然后以这个特殊的数字为分界点,向前求后缀和,向后求前缀和,找到前后缀和分别的mx和mn,然后把mn相加,mx相加,分别插入该特殊数字

``` cpp
void solve()
{
    int n;  std::cin >> n;
    int p = n + 1;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        if (a[i] < -1 || a[i] > 1 || a[i] == 0) p = i;
    }
    int mx1 = 0, mx2 = 0, mn1 = 0, mn2 = 0;
    std::vector<int> l(n + 1), r(n + 1);
    for (int i = 1;i < p;i++)
    {
        l[i] = std::max(a[i], l[i - 1] + a[i]);
        r[i] = std::min(a[i], r[i - 1] + a[i]);
        mx1 = std::max(mx1, l[i]);
        mn1 = std::min(mn1, r[i]);
    }
    for (int i = p + 1;i <= n;i++)
    {
        l[i] = std::max(a[i], l[i - 1] + a[i]);
        r[i] = std::min(a[i], r[i - 1] + a[i]);
        mx2 = std::max(mx2, l[i]);
        mn2 = std::min(mn2, r[i]);
    }
    mn1 = std::min(mn1, mn2);
    mx1 = std::max(mx1, mx2);
    int ans = mx1 - mn1 + 1;
    std::map<int, int> mp;
    for (int i = mn1;i <= mx1;i++)
        mp[i]++;

    if (p != n + 1) {
        if (mp[a[p]]++ == 0) ans++;
        int tmp = 0;
        int mn1 = 0, mx1 = 0, mn2 = 0, mx2 = 0;
        for (int i = p + 1;i <= n;i++)
        {
            tmp += a[i];
            mn1 = std::min(mn1, tmp);
            mx1 = std::max(mx1, tmp);
        }
        tmp = 0;
        for (int i = p - 1;i >= 1;i--) {
            tmp += a[i];
            mn2 = std::min(mn2, tmp);
            mx2 = std::max(mx2, tmp);
        }
        mn1 = mn1 + mn2;
        mx1 = mx1 + mx2;
        for (int i = mn1;i <= mx1;i++)
            if (mp[i + a[p]]++ == 0) ans++;
    }
    std::cout << ans << '\n';
    for (auto [x, _] : mp)  std::cout << x << " ";
    std::cout << '\n';
}
```

4. [Problem - D - Codeforces](https://codeforces.com/contest/2043/problem/D)

题目大意:给定一个区间和一个gcd之后的结果`g`,现在要求构造两个数`A,B`,要求使得`std::abs(A-B)`的值最大,并且`A,B`的gcd结果为`g`

思路:可以根根据区间确定最少和最多需要多少个g,然后从最大长度开始枚举,并且枚举起点,判断此时A,B的gcd结果

``` cpp
void solve()
{
    i64 l, r, g;    std::cin >> l >> r >> g;
    i64 a = (l + g - 1) / g;
    i64 b = r / g;

    for (i64 len = b - a;len >= 0;len--) {
        for (i64 i = a;i + len <= b;i++)
            if (std::gcd(i, i + len) == 1)
            {
                std::cout << i * g << " " << (i + len) * g << '\n';
                return;
            }
    }
    std::cout << "-1 -1\n";
}

```

