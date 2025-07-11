# Round957

1. [Problem - A - Codeforces](https://codeforces.com/contest/1992/problem/A)暴力枚举一下即可

2. [Problem - B - Codeforces](https://codeforces.com/contest/1992/problem/B) 很容易注意到需要保留最大的点,其余的点先分为1,再全加起来
3. [Problem - C - Codeforces](https://codeforces.com/contest/1992/problem/C)

题目大意:设计一个排列,满足m,k的要求

很容易发现应该把大于等于k的逆序放前面,小于等于m的顺序放后面

~~~ cpp
int n, m, k;    std::cin >> n >> m >> k;
for (int i = n;i >= k;i--)  std::cout << i << " ";
for (int i = m + 1;i <= k - 1;i++) std::cout << i << " ";
for (int i = 1;i <= m;i++)   std::cout << i << " ";
std::cout << '\n';
~~~

4. [Problem - D - Codeforces](https://codeforces.com/contest/1992/problem/D)

   题目大意:有一段路程,其中有log有water还有crocodile(鳄鱼),问能否在不消耗过多体力(游泳)的情况下抵达终点[0-----n + 1]

   思路:DP,注意到m比较小,因此很容易注意到可以从之前的点跳到i,设置f[i]为此时消耗的体力,最后判断一下f[n + 1]消耗的体力是否超过限制

   ~~~ cpp
   void solve()
   {
       int n, m, k;    std::cin >> n >> m >> k;
       std::string s;  std::cin >> s;
       s = " " + s;
       std::vector<int> f(n + 2, inf);
       f[0] = 0;
       for (int i = 1;i <= n;i++)
       {
           if (s[i] == 'C') continue;
           if (s[i - 1] == 'W')
               f[i] = f[i - 1] + 1;
           for (int j = 1;j <= m;j++)
               if (i >= j && (i - j == 0 || s[i - j] == 'L')) f[i] = std::min(f[i], f[i - j]);
       }
       if (s[n] == 'W') f[n + 1] = f[n] + 1;
       for (int i = 1;i <= m;i++)
           if (n + 1 - i >= 0 && (n + 1 - i == 0 || s[n + 1 - i] == 'L')) f[n + 1] = std::min(f[n + 1], f[n + 1 - i]);
   
       if (f[n + 1] <= k)  std::cout << "YES\n";
       else std::cout << "NO\n";
   }
   ~~~

   

5. [Problem - E - Codeforces](https://codeforces.com/contest/1992/problem/E)

   题目大意:给一个数字`n`,将其当作字符串复制a遍,然后删除尾部的b个字符,使其剩余的字符串转换为数字之后恰好等于`n * a - b`

   思路:首先可以注意到`n,a`的范围,可以发现`n * a <= 1e6`,也就是形成的字符串的字符数最多为6个,因此可以想到,枚举`a`然后枚举字符的位数,从而求出`b`,再由得到的数字计算出`n * a- b`,然后判断得到的字符串是否等于该数字

   ~~~ cpp
   void solve()
   {
       int n;  std::cin >> n;
       std::vector<pii> res;
       std::string n_str = std::to_string(n);
       int len = n_str.size();
       std::string tmp = "";
       while (tmp.size() <= 10) tmp += n_str;
   
       for (int i = 1;i <= 10000;i++) {
           for (int j = 1;j <= 6;j++) {
               int b = i * len - j;
               int ans = n * i - b;
               if (b < 1 || b > std::min(10000, i * n))   continue;
               if (std::to_string(ans) == tmp.substr(0, j))
                   res.push_back({ i,b });
           }
       }
       std::cout << res.size() << '\n';
       for (auto [a, b] : res) std::cout << a << " " << b << '\n';
   }
   ~~~

   6. https://codeforces.com/contest/1992/problem/F

      题目大意:给一个数字x和一个数组a,要求把a分为最少数量的集合,并且要求每一段内,不能通过选一些元素相乘得到x

      思路:首先我们发现,我们只关心x的因子,对于其他的数一定是无法通过组合得到x的,可以从左到右遍历数组,如果当前的元素可以和已有内容组合成x,则将当前元素放在新的集合中,否则就和已有内容组合新的内容,因此开三个set,一个存储x的因子,一个存储当前的内容,一个用于临时更新(防止一些更新上的问题)

      ~~~ cpp
      void solve()
      {
          int n, x;   std::cin >> n >> x;
          std::vector<int> a(n + 1);
          for (int i = 1;i <= n;i++)   std::cin >> a[i];
          std::set<int> vis;
          for (int i = 2;i <= x / i;i++) {
              if (x % i != 0) continue;
              vis.insert(i);
              if (x / i != i)     vis.insert(x / i);
          }
      
          int ans = 1;
          std::set<int> now;
          for (int i = 1;i <= n;i++) {
              if (!vis.count(a[i])) continue;
              if (now.count(x / a[i])) {
                  ans++;
                  now.clear();
                  now.insert(a[i]);
              }
              else {
                  std::set<int> tmp;
                  for (auto d : vis) {
                      if (now.count(d) && vis.count(d * a[i]))
                          tmp.insert(d * a[i]);
                  }
                  tmp.insert(a[i]);
                  for (auto t : tmp)  now.insert(t);
              }
          }
          std::cout << ans << '\n';
      }
      ~~~

      

7. https://codeforces.com/contest/1992/problem/G

   题目大意:给一个n,要求从1-n之中任意选择一些元素形成一个集合(S),然后找到该集合的`(len(S) +1)th MEX`,把所有这样的集合的MEX值全部加起来

   思路:纯思维题,可以枚举集合的大小`i`和需要的MEX`j`,因此我们需要构造j为第`i + 1`个mex,也就是1~j-1当中,需要留下i个,因此需要从`j-1`个当中选择`j-1-i`放入集合当中,如果此时集合还有没有放入的元素,就从`j+1~~n`当中选择并放入<br>这个题要注意一些边界问题,尤其是关于`t *= comb.C(n - j, i - (j - 1 - i));`

   ~~~ cpp
   void solve()
   {
       int n;  std::cin >> n;
       Z ans = 1;
       for (int i = 1;i <= n;i++)
           for (int j = i + 1;j <= 2 * i + 1;j++)
           {
               Z t = j * comb.C(std::min(n, j - 1), j - 1 - i);
               if (n >= j)
                   t *= comb.C(n - j, i - (j - 1 - i));
               else if (j - 1 - i != i)t = 0;
               ans += t;
           }
       std::cout << ans << '\n';
   }
   ~~~

   

