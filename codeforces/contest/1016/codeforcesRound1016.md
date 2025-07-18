1. [Problem - A - Codeforces](https://codeforces.com/contest/2093/problem/A)

题目大意:给定k个元素,要求k个元素是对称的,判断这k个数的和是否可以表示任意实数

思路:因为是成对出现的,因此只有中间的元素有可能构成奇数,所以判断是否有非成对出现的中间的那个数字即可

``` cpp
void solve()
{
    int n;  std::cin >> n;
    if (n % 2)   std::cout << "YES\n";
    else std::cout << "NO\n";
}
```

2. [Problem - B - Codeforces](https://codeforces.com/contest/2093/problem/B)

   题目大意:给定一个数字,数字的花费是 数字除以每个数位之和,现在可以在数字当中删除一些数位,求使得花费最小的时候至少要删除多少个数位

   思路:由于后导0对于数字大小很重要,因此需要全部删除,然后保留一个有效数位,其余前面的有效数位都可以删除

   ```cpp
   void solve()
   {
       std::string s;  std::cin >> s;
       int len = s.size();
       int i = len - 1;
       int ans = 0;
       for (;i >= 0;i--)
       {
           if (s[i] == '0') ans++;
           else break;
       }
       i--;
       for (;i >= 0;i--)
           if (s[i] != '0') ans++;
       std::cout << ans << '\n';
   }
   
   ```

   3. [Problem - C - Codeforces](https://codeforces.com/contest/2093/problem/C)

      题目大意:现在给定一个数字x,使其重复k次,判断新得到的数字是否是质数

      思路:由观察可以知道,一个数字重复k次,必定可以把该数字本身当成因子,所以都不是质数,而当k为1的时候,直接判断该数字是否是素数即可.但是有特殊情况即为1重复多次,这种情况下直接硬算即可

      ``` cpp
      std::string a[7] = { "1","11","111","1111","11111","111111","1111111" };
      void solve()
      {
          int n, k;   std::cin >> n >> k;
          auto check = [&](int x) {
              if (x < 2) return 0;
              for (int i = 2;i * i <= x;i++)
                  if (x % i == 0) return 0;
              return 1;
              };
      
          if (k == 1)
              std::cout << (check(n) ? "YES\n" : "NO\n");
          else {
              if (n == 1)
                  std::cout << (check(std::stoi(a[k - 1])) ? "YES\n" : "NO\n");
              else std::cout << "NO\n";
          }
      }
      ```

      

   4. [Problem - D - Codeforces](https://codeforces.com/contest/2093/problem/D)

      题目大意:递归,平面按照一定的规则摆放数字,现在有两种询问: x,y处摆放的是哪个数字,以及某个数字的坐标位置

      思路:非常好的考察递归的题,但是要注意一下判定递归范围的边界

      ``` cpp
      i64 ask1(int x, int y, int n) {
          if (n == 0) return 1;
          i64 cnt = (1 << n);
          i64 area = cnt * cnt / 4;
      
          int half = (1 << (n - 1));
          if (x <= half && y <= half)
              return ask1(x, y, n - 1) + area * 0;
          else if (x > half && y > half)
              return ask1(x - cnt / 2, y - cnt / 2, n - 1) + area * 1;
          else if (x <= half && y > half)
              return ask1(x, y - cnt / 2, n - 1) + area * 3;
          else if (x > half && y <= half)
              return ask1(x - cnt / 2, y, n - 1) + area * 2;
      }
      
      pii ask2(i64 num, int n) {
          if (n == 0) return { 1,1 };
          i64 cnt = (1 << n);
          i64 area = cnt * cnt / 4;
      
          if (num <= area) {
              auto [x, y] = ask2(num, n - 1);
              return { x,y };
          }
          else if (num <= area * 2) {
              auto [x, y] = ask2(num - area, n - 1);
              return { x + cnt / 2,y + cnt / 2 };
          }
          else if (num <= area * 3) {
              auto [x, y] = ask2(num - area * 2, n - 1);
              return { x + cnt / 2,y };
          }
          else if (num <= area * 4) {
              auto [x, y] = ask2(num - area * 3, n - 1);
              return { x,y + cnt / 2 };
          }
      }
      void solve()
      {
          int n, q;   std::cin >> n >> q;
          while (q--) {
              std::string op; std::cin >> op;
              if (op == "->") {
                  int x, y;   std::cin >> x >> y;
                  std::cout << ask1(x, y, n) << '\n';
              }
              else {
                  i64 x;  std::cin >> x;
                  pii ans = ask2(x, n);
                  std::cout << ans.first << " " << ans.second << '\n';
              }
          }
      }
      ```

      

5. [Problem - E - Codeforces](https://codeforces.com/contest/2093/problem/E)

   题目大意:给定一个数组,和一个数字k,现在要求把数组分成k段,使得每段的mex的最小值最大

   思路:最小值最大,很容易想到二分,随后在数组当中时,只要当前mex大于等于需要的,就cnt++重新开始找新的

   **注意:**这里的复杂度是双层lgn,可能会因为set的大常数tle,需要进行一定的剪枝,可以使用一个辅助数组来判定mex,以此来省去一个set的复杂度,只要当数字内存入的数字 >= 需要的mex即为此时mex达到要求

   ``` cpp
   void solve()
   {
       int n, k;   std::cin >> n >> k;
       std::vector<int> a(n + 1);
       for (int i = 1;i <= n;i++) {
           std::cin >> a[i];
       }
       if (k == 1)
       {
           std::sort(a.begin() + 1, a.end());
           int mex = 0;
           for (int i = 1;i <= n;i++)
               if (a[i] == mex) mex++;
           std::cout << mex << '\n';
           return;
       }
   
       auto check = [&](int x) -> bool {
           int cnt = 0; std::set<int> st;
           int mex = 0;
           for (int i = 1;i <= n;i++) {
               st.insert(a[i]);
               while (st.count(mex) && mex < x) mex++;
               if (mex == x) {
                   cnt++;
                   mex = 0;
                   st.clear();
               }
               if (cnt >= k) return 1;
           }
           return 0;
           };
       int l = 0, r = n + 1, mex = 0;
       while (l <= r) {
           int mid = l + r >> 1;
           if (check(mid)) mex = mid, l = mid + 1;
           else r = mid - 1;
       }
       std::cout << mex << '\n';
   }
   ```

   6. [Problem - F - Codeforces](https://codeforces.com/contest/2093/problem/F)

      题目大意:给定一个目标字符串数组,和一些待定字符串数组,现在要从待定字符串数组当中随机的填入目标字符串数组,虽然是对应的填入,但是填入的顺序是随机的,因此要按照最坏情况考虑,要求找到一个操作序列,使得按照该操作序列填入之后,目标字符串被填满,输出该操作序列的最小值

      思路:首先对于目标字符串数组的每一位,如果待定数组当中没有需要的字符串,那么就一定无法完成目标.其次我们可以一次尽可能多填一点,然后把不匹配的删去重新填,因此最多只需要填入n + 最小不匹配数*2次即可

      ``` cpp
      void solve()
      {
          int n, m;   std::cin >> n >> m;
          std::vector<std::string> a(n + 1);
          std::vector b(m + 1, std::vector<std::string>(n + 1));
          for (int i = 1;i <= n;i++)   std::cin >> a[i];
          for (int i = 1;i <= m;i++)
              for (int j = 1;j <= n;j++)   std::cin >> b[i][j];
      
          for (int i = 1;i <= n;i++)
          {
              int f = 0;
              for (int j = 1;j <= m;j++) {
                  if (a[i] == b[j][i]) {
                      f = 1;
                      break;
                  }
              }
              if (!f) {
                  std::cout << "-1\n";
                  return;
              }
          }
      
          int min = inf;
          for (int i = 1;i <= m;i++)
          {
              int cnt = 0;
              for (int j = 1;j <= n;j++)
                  if (a[j] != b[i][j])    cnt++;
              min = std::min(min, cnt);
          }
          std::cout << n + min * 2 << '\n';
      }
      ```

      7. [codeforces.com/contest/2093/problem/G](https://codeforces.com/contest/2093/problem/G)

         题目大意:给定一个数组和一个数字k,现在要求在数组当中找到两个数的异或值大于等于k,并且使得这两个数字之间的距离最短

         思路:首先很容易想到,这两个数字即为距离的边界.<br>其次该题有两种写法,一种按位考虑的位运算,一种是字典树,主要的核心思想都是若k的该位为1时,找的两个数在该位的异或值必定需要是1.若k的改为是0,如果可以找到两个数,在之前的异或值符合要求,且在该为的异或值是1,那么这两个数就可以当成答案考虑

         位运算写法:

         ``` cpp
         void solve()
         {
             int n, k;   std::cin >> n >> k;
             std::vector<int> a(n + 1), b(n + 1);
             for (int i = 1;i <= n;i++)   std::cin >> a[i];
             if (k == 0) {
                 std::cout << "1\n";
                 return;
             }
         
             int limit = 0, ans = inf;
             for (int j = 30;j >= 0;j--) {
                 if (k & (1 << j)) {
                     limit |= 1 << j;
                     for (int i = 1;i <= n;i++)
                         if (a[i] & (1 << j)) b[i] |= 1 << j;
                 }
                 else {
                     std::map<int, int> mp[2];
                     for (int i = 1;i <= n;i++) {
                         bool flag = a[i] & (1 << j);
                         if (mp[!flag].count(limit ^ b[i]))  ans = std::min(ans, i - mp[!flag][limit ^ b[i]] + 1);
                         mp[flag][b[i]] = i;
                     }
                 }
             }
             std::map<int, int> mp;
             for (int i = 1;i <= n;i++)
             {
                 if (mp.count(limit ^ b[i])) ans = std::min(ans, i - mp[limit ^ b[i]] + 1);
                 mp[limit & b[i]] = i;
             }
             std::cout << (ans == inf ? -1 : ans) << '\n';
         }
         ```

         字典树写法:

         ``` cpp
         struct Trie {
             int n, idx;
             vector<vector<int>> ch;
             vector<int> pos;
             Trie(int n) {
                 this->n = n;
                 idx = 0;
                 ch.assign(30 * (n + 1), vector<int>(2, -1));
                 pos.resize(30 * (n + 1));
             }
             void insert(int x, int p) {
                 int u = 0;
                 for (int i = 30; ~i; i--) {
                     int& v = ch[u][x >> i & 1];
                     if (v == -1) v = ++idx;
                     u = v;
                     pos[u] = p;
                 }
             }
         
             int query(int x, int k) {
                 int c = 0;
                 int mxidx = 0;
                 for (int i = 30;~i;i--) {
                     int b = x >> i & 1;
                     int t = k >> i & 1;
                     if (t == 0 && ch[c][b ^ 1] != -1)
                         mxidx = std::max(mxidx, pos[ch[c][b ^ 1]]);
                     c = ch[c][b ^ t];
                     if (c == -1) break;
                 }
                 if (c != -1)
                     mxidx = std::max(mxidx, pos[c]);
                 return mxidx;
             }
         
             void clear() {
                 for (int i = 0;i <= idx;i++) {
                     pos[i] = 0;
                     for (int j = 0;j <= 1;j++)
                         ch[i][j] = -1;
                 }
                 idx = 0;
             }
         }tr(2e5);
         
         void solve()
         {
             int n, k;   std::cin >> n >> k;
             std::vector<int> a(n + 1);
             for (int i = 1;i <= n;i++)   std::cin >> a[i];
             if (k == 0) {
                 std::cout << "1\n";
                 return;
             }
             // Trie tr()
             tr.clear();
             int ans = n + 1;
             for (int i = 1;i <= n;i++) {
                 int mxidx = tr.query(a[i], k);
                 if (mxidx > 0) ans = std::min(ans, i - mxidx + 1);
                 tr.insert(a[i], i);
             }
             std::cout << (ans > n ? -1 : ans) << '\n';
         }
         ```

         



​	