1. [Problem - A - Codeforces](https://codeforces.com/contest/2051/problem/A)

   题目大意:A在第i天训练,则B必须要在第i+1天训练,问A要如何安排训练计划才能使得差值最大

   思路:找差值大于0训练即可,然后加上A的最后一天的

   ``` cpp
   void solve()
   {
       int  n; std::cin >> n;
       std::vector<int> a(n + 1), b(n + 1);
       for (int i = 1;i <= n;i++)   std::cin >> a[i];
       for (int i = 1;i <= n;i++)   std::cin >> b[i];
       i64 ans = 0;
       for (int i = 1;i <= n - 1;i++)
           if (a[i] - b[i + 1] > 0)    ans += a[i] - b[i + 1];
       ans += a[n];
       std::cout << ans << '\n';
   }
   ```

   

2. [Problem - B - Codeforces](https://codeforces.com/contest/2051/problem/B)

   题目大意:给定一个总数n,现在第一天可以走a米,第二天b米,第三天c米,以此类推,问第几天的时候会走完

   ``` cpp
   void solve()
   {
       int n, a, b, c; std::cin >> n >> a >> b >> c;
       int sum = a + b + c;
       int ans = n / sum * 3;
       n -= n / sum * sum;
       if (n > 0) n -= a, ans++;
       if (n > 0) n -= b, ans++;
       if (n > 0) n -= c, ans++;
       std::cout << ans << '\n';
   }
   ```

   

3. [Problem - C - Codeforces](https://codeforces.com/contest/2051/problem/C)

   题目大意:现在A知道一些问题的答案,现在有一系列题提问,第`ai`套题是指除了`ai`问题以外的所有题目都有,问他可以通过那些套题

   思路:很容易发现如果A不知道的题大于等于2,则一定无法通过所有的提问,当差值为1的时候,若他不知道`ai`问题的答案,则除了该套题其他套题都无法通过

   ``` cpp
   void solve()
   {
       int n, m, k;    std::cin >> n >> m >> k;
       std::vector<int> a(m + 1);
       for (int i = 1;i <= m;i++)   std::cin >> a[i];
       std::vector<int> know(k + 1);
       for (int i = 1;i <= k;i++)   std::cin >> know[i];
       std::string ans = "";
       if (n == k) {
           for (int i = 1;i <= m;i++)
               ans += "1";
           std::cout << ans << '\n';
       }
       else if (n - k >= 2) {
           for (int i = 1;i <= m;i++)
               ans += "0";
           std::cout << ans << '\n';
       }
       else {
           std::sort(know.begin() + 1, know.end());
           int no = 1;
           for (int i = 1;i <= k;i++, no++) if (know[i] != no) break;
           for (int i = 1;i <= m;i++) {
               if (a[i] == no) ans += "1";
               else ans += "0";
           }
           std::cout << ans << '\n';
       }
   }
   ```

   

4. [Problem - D - Codeforces](https://codeforces.com/contest/2051/problem/D)

   题目大意:给定一个数组,和边界L,R,现在要求从数组中删除两个数字,使得删除完之后数组的和落在这个区间当中

   思路:二分,我们可以固定选择的两个数当中较小的那个数字,然后二分需要的较大的数字

   ``` cpp
   void solve()
   {
       int n;  std::cin >> n;
       i64 x, y;   std::cin >> x >> y;
       i64 sum = 0;
       std::vector<int> a(n + 1);
       for (int i = 1;i <= n;i++) {
           std::cin >> a[i];
           sum += a[i];
       }
       std::sort(a.begin() + 1, a.end());
   
       i64 l = sum - y, r = sum - x;
       i64 ans = 0;
       for (int i = 1;i <= n - 1;i++) {
           int left = std::lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
           if (left == n + 1) continue;
           int right = std::upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin() - 1;
           if (right < left) continue;
           ans += right - left + 1;
       }
       std::cout << ans << '\n';
   }
   ```

5. [Problem - E - Codeforces](https://codeforces.com/contest/2051/problem/E)

   题目大意:现在有n个人,每个人有一个ai,和bi,当定价小于等于ai的时候,他们会购买,然后给出好评,如果定价小于等于bi,他们也会购买,但是会给出差评,当价格大于bi,他们就不会购买了

   思路:依旧是二分,但是这个题目要注意到最终的价格一定是某个ai或者bi,可以使用反证法来证明,确定了这个之后,就可以对所有的ai和bi去二分,查询有多少人会购买且好评,有多少人会购买,二者相减就会得到购买但是给差评的人数,只要该人数小于等于给定的k,则视为一次合法

   ``` cpp
   void solve()
   {
       int n, k;   std::cin >> n >> k;
       std::vector<int> a(n + 1), b(n + 1), v;
       for (int i = 1;i <= n;i++) {
           std::cin >> a[i];
           v.push_back(a[i]);
       }
       for (int i = 1;i <= n;i++) {
           std::cin >> b[i];
           v.push_back(b[i]);
       }
   
       std::sort(a.begin() + 1, a.end());
       std::sort(b.begin() + 1, b.end());
       std::sort(v.begin(), v.end());
       v.erase(std::unique(v.begin(), v.end()), v.end());
   
       i64 ans = 0;
       for (auto x : v) {
           int cnt1 = n - (std::lower_bound(a.begin(), a.end(), x) - a.begin() - 1); //买 且好评的
           int cnt2 = n - (std::lower_bound(b.begin(), b.end(), x) - b.begin() - 1); //一定会买的
           if (cnt2 - cnt1 <= k)   ans = std::max(ans, (i64)x * cnt2);
       }
       std::cout << ans << '\n';
   }
   ```

   

6. [Problem - F - Codeforces](https://codeforces.com/contest/2051/problem/F)

   题目大意:给定一副扑克牌,告诉joker的位置在m,现在有一序列的操作位置,每次可以对选定的操作位置将其放在第一或者最后一张,然后问你joker的位置可能出现的位置有多少个

   思路:这是一个区间操作问题,涉及到区间延展和区间区间合并,我们可以注意到选定的位置x和joker可能出现的区间,如果x在之前,则区间应该向左延申一格,若x在之后,区间应该向右延申一格,若x就落在区间当中,则应该新开两个开头的区间,并且此时的区间不延展(重点)

   ``` cpp
   void solve()
   {
       int n, m, q;    std::cin >> n >> m >> q;
       std::vector<pii> ans;
       ans.push_back({ m,m });
       while (q--) {
           int p;  std::cin >> p;
           std::vector<pii> tmp;
           for (auto [l, r] : ans) {
               if (p < l) tmp.push_back({ l - 1,r });
               else if (p > r)  tmp.push_back({ l,r + 1 });
               else {
                   tmp.push_back({ 1,1 });
                   tmp.push_back({ n,n });
                   if (l != r)
                       tmp.push_back({ l,r });
               }
           }
           ranges::sort(tmp);
           std::vector<pii> merge;
           for (auto [l, r] : tmp) {
               if (merge.empty() || merge.back().second < l)
                   merge.push_back({ l,r });
               else merge.back().second = r;
           }
           ans = merge;
           int res = 0;
           for (auto [l, r] : ans) {
               res += r - l + 1;
           }
           std::cout << res << " ";
       }
       std::cout << '\n';
   }
   ```

   

7.[Problem - G - Codeforces](https://codeforces.com/contest/2051/problem/G)

题目大意:有一些小蛇,和一些对他们操作的序列,小蛇会向右延申一格,也会从左边缩短一格,现在要求所有小蛇在按顺序操作的时候,不会碰撞边界和其他小蛇,问怎么安排他们的初始位置会使得小蛇能抵达的最远位置最短?

思路:n很小,所以想到使用状压dp解决问题,`dp[S][i]`为当状态为S的时候,第`i`小蛇的初始位置至少需要放在哪里,因此答案就是`dp[1111...111][i]`,这里i要遍历所有的小蛇,并且注意这里的只是i的初始位置,所以还要遍历操作序列看其需要向右延展多少格<br>还有个需要解决的就是不同状态之间如何转移,我们可以定义一格`d[i][j]`代表`i和j`小蛇之间需要离的最短距离,然后就可以状态转移了`f[i | (1 << k)][k] = std::min(f[i | (1 << k)][k], f[i][j] + d[j][k])`

``` cpp
void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<pii> a(q + 1);
    for (int i = 1;i <= q;i++) {
        std::cin >> a[i].first;
        std::string s;  std::cin >> s;
        a[i].second = (s == "+" ? 1 : 0);
    }

    std::vector f(1 << n + 1, std::vector<int>(n + 1, inf));
    std::vector d(n + 1, std::vector<int>(n + 1));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            if (i == j) continue;
            int dis = 1;
            int l = 1, r = 2;
            for (auto [x, op] : a) {
                if (x == i && op == 1) {
                    l++;
                    if (l == r)
                    {
                        dis++;
                        r++;
                    }
                }
                if (x == j && op == 0)
                    r++;
            }
            d[i][j] = dis;
        }

    for (int i = 1;i <= n;i++)
        f[1 << i][i] = 1;

    for (int i = (1 << 1);i < (1 << n + 1);i += 2)
        for (int j = 1;j <= n;j++)
        {
            for (int k = 1;k <= n;k++)
            {
                // if (i == 12 && j == 3) std::cout << "DEBUG";
                if (i >> k & 1) continue;
                f[i | (1 << k)][k] = std::min(f[i | (1 << k)][k], f[i][j] + d[j][k]);
            }
        }

    int ans = inf;
    for (int i = 1;i <= n;i++) {
        int res = f[(1 << n + 1) - 2][i];
        for (auto [x, op] : a)
            if (x == i && op == 1) res++;
        ans = std::min(ans, res);
    }
    std::cout << ans << '\n';

}
```

