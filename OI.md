# $\huge{\texttt{OI}}$

## $\texttt{Section 1  /  OI常犯错误}$

1．双层循环的循环变量重名；

2．多测不清空；

3．数据范围过小；

4．数组过小/过大；

5．使用多维$\texttt{STL}$容器，并用数组读入并将数组入队至多维$\texttt{STL}$容器时，数组读入从下标 $\texttt{1}$ 开始。实际上应从下标 $\texttt{0}$ 开始读入，因为$\texttt{STL}$容器是从下标 $\texttt{0}$ 开始的。详见[P2776 [SDOI2007\] 小组队列](https://www.luogu.com.cn/problem/P2776)；

6．求取最大值/最小值时，$\texttt{mx}$ / $\texttt{mi}$ 不够小/大，这时需要调用`climits`或者`limits`库；

7．`max` / `min`函数内使用其他函数；

8．$\texttt{max} / \texttt{min}$函数内二变量数据类型不一致

9．除或取余时，$\texttt{a / b}$ 或 $\texttt{a}\:\%\:\texttt{b}$ 时，$\texttt{b = 0}$ 或 $\texttt{a}$ 为小数或 $\texttt{b}$ 为小数

10．字符串遍历时从$\texttt{1}$开始；

11．题目没有保证一个输入数据的某个特殊性质时按照保证后写，其实正确的做法是要针对这个特殊性质做特判，形如[【LGR-145-Div.4】洛谷入门赛 #14 D T352131 枚举结构](https://www.luogu.com.cn/problem/T352131?contestId=114059)；

12．循环条件写反；

13．函数数据类型错误；

14．设字符串 $\texttt{s}$ 为`abc123`，赋值给字符串 $\texttt{str}$ 时 $\texttt{str}$ 没有`resize`；

15．读入数据规模极大的时候使用`cin`、`cout`，即使关闭同步流后仍然超时，这时必须使用快读快写。如[P6033 [NOIP2004 提高组\] 合并果子 加强版](https://www.luogu.com.cn/problem/P6033) ；

16．使用了`deque`，由于`deque`常数过大，可能会导致$\texttt{TLE}$；

17．深搜忘记使用什么数据结构，正确答案如后。一般情况下，深搜使用栈数据结构，广搜使用队列数据结构;具有n个顶点，e条边的图采用邻接表存储结构,进行深度与广度优先遍历运算的时间复杂度均为 $\texttt{O(n+e)}$ ；

18. 快读快写返回值写成了`int`，实际上应该是`long long`，形如[AtCoder ABC324-B](https://atcoder.jp/contests/abc324/tasks/abc324_b)；
19. 快读快写返回值写成了`int`，实际上应该是`long long`，形如[AtCoder ABC324-B](https://atcoder.jp/contests/abc324/tasks/abc324_b)；
20. 使用`memset`赋值时不是 $\texttt{0}$ 或者 $\texttt{0x3f3f3f}$；
21. 题目中有向图图里把双向图理解成了单向图，实际上，含有形如“可以从一个点到达另一个点”这句话的一般都是双向图。
22. 开数组时没有看到以科学计数法形式写出的数据范围的系数；
23. 二维数组开太大可能会导致 $\texttt{TLE}$；
24. 取模没有取完，比如写`sum *= a;`时，题目要求取模，不能写`sum *= (a % mod);`，因为你只对 $\texttt{a}$ 取了模，没有对最终结果 $\texttt{sum}$ 进行取模；
25. 在遍历一个数组时，需要对当前的数组下标取模所得的结果作为下标并访问，如`mx = max(mx, a[(i + 1) % mod]);`，此时下标需要从 $\texttt{0}$ 开始；
26. 在同时使用`cin`和`getline`来读取一个字符串且`cin`为先`getline`为后时，会发生后者无法输入的情况，这时需要把前面的`cin`改成`getchar`或者在`cin`和`getline`间写`getchar()`才可以解决问题。但是如果二者皆为`getchar`，那么二者之间是不可以写`getchar()`的，因为这样子会吃掉第二个字符串的第一个字符，如[P1308 [NOIP2011 普及组] 统计单词数](https://www.luogu.com.cn/problem/P1308)，代码见脚注$\texttt{1}$。

## $\texttt{Section 2 / OI部分重点知识点}$

- `map` & `multimap` & `unordered_map` & `unordered_multimap`
  
  - `map` & `multimap`
    
    - `multimap`的`key`可重复；
    
    - `multimap`没有`operator[ ]`功能。
  
  - `map` & `unordered_map`
    
    - `map` 本质是红黑树，`unordered_map`则是哈希表；
    
    - `map`是具有有序性的，`unordered_map`则是无序性的；
    
    - `map`适用于有顺序要求的场景，`unordered_map`则适用于有查找需求的场景，因为`unordered_map`的查找是 $\texttt{O(1)}$ 的，`map`则是 $\texttt{O(log n)}$ 的。

## $\texttt{Section 3 / 脚注}$

$\texttt{1.}$代码如下

- 出现的问题代码
  
  ```cpp
  #include <iostream>
  #include <string>
  using namespace std;
  string s1, s2;
  int main(){
      cin >> s1;
      getline(cin, s2);
      cout << s1 << endl << s2;
      return 0;
  }
  ```

- 第一种解决办法
  
  ```cpp
  #include <iostream>
  #include <string>
  using namespace std;
  string s1, s2;
  int main(){
      getline(cin, s1);
      getline(cin, s2);
      cout << s1 << endl << s2;
      return 0;
  }
  ```

- 第二种解决办法
  
  ```cpp
  #include <iostream>
  #include <string>
  using namespace std;
  string s1, s2;
  int main(){
      cin >> s1;
      getchar();
      getline(cin, s2);
      cout << s1 << endl << s2;
      return 0;
  }
  ```

- 错误的`getchar()`用法
  
  ```cpp
  #include <iostream>
  #include <string>
  using namespace std;
  string s1, s2;
  int main(){
      getline(cin, s1);
      getchar();
      getline(cin, s2);
      cout << s1 << endl << s2;
      return 0;
  }
  ```