# $ \texttt{OI}$

## $\texttt{Section 1  /  OI常犯错误}$

1．$\color{red}{双层循环的循环变量重名；}$

2．$\color{red}{多测不清空；}$

3．$\color{red}{数据范围过小；}$

4．数组过小/过大；

5．使用多维STL容器，并用数组读入并将数组入队至多维STL容器时，数组读入从下标 $1$ 开始。实际上应从下标 $0$ 开始读入，因为STL容器是从下标 $0$ 开始的。详见[P2776 [SDOI2007\] 小组队列](https://www.luogu.com.cn/problem/P2776)；

6．求取最大值/最小值时，$mx$ / $mi$ 不够小/大，这时需要调用`climits`库；

7．`max` / `min`函数内使用其他函数；

8．$\color{red}{max/min函数内二变量数据类型不一致；}$

9．除或取余时，$a / b$ 或 $a % b$ 时，$b = 0$ 或 $a$ 为小数或 $b$ 为小数

10．$\color{red}{字符串遍历时从1开始；}$

11．$\color{red}{题目没有保证一个输入数据的某个特殊性质时按照保证后写，其实正确的做法是要针对这个特殊性质做特判，形如}$[【LGR-145-Div.4】洛谷入门赛 #14 D T352131 枚举结构](https://www.luogu.com.cn/problem/T352131?contestId=114059)；

12．循环条件写反；

13．函数数据类型错误；

14．设字符串 $s$ 为"abc123"，赋值给字符串 $str$ 时 $str$ 没有`resize`；

15．读入数据规模极大的时候使用`cin`、`cout`，即使关闭同步流后仍然超时，这时必须使用快读快写。如[P6033 [NOIP2004 提高组\] 合并果子 加强版](https://www.luogu.com.cn/problem/P6033) ；

16．使用了`deque`，由于`deque`常数过大，可能会导致TLE；

17．深搜忘记使用什么数据结构，正确答案如后。一般情况下，深搜使用栈数据结构，广搜使用队列数据结构;具有n个顶点，e条边的图采用邻接表存储结构,进行深度与广度优先遍历运算的时间复杂度均为 $O(n+e)$ ；

18. 快读快写返回值写成了`int`，实际上应该是`long long`，形如[AtCoder ABC324-B](https://atcoder.jp/contests/abc324/tasks/abc324_b)。
19. 快读快写返回值写成了`int`，实际上应该是`long long`，形如[AtCoder ABC324-B](https://atcoder.jp/contests/abc324/tasks/abc324_b)；
20. 使用`memset`赋值时不是 `0` 或 `0x3f3f3f`；
21. 题目中有向图图里把双向图理解成了单向图，实际上，含有形如“可以从一个点到达另一个点”这句话的一般都是双向图。
22. 开数组时没有看到以科学计数法形式写出的数据范围的系数。

## $\texttt{Section 2 / OI部分重点知识点}$

- `map` & `multimap` & `unordered_map` & `unordered_multimap`
  
  - `map` & `multimap`
    
    - `multimap`的`key`可重复；
    
    - `multimap`没有`operator[ ]`功能。
  
  - `map` & `unordered_map`
    
    - `map` 本质是红黑树，`unordered_map`则是哈希表；
    
    - `map`是具有有序性的，`unordered_map`则是无序性的；
    
    - `map`适用于有顺序要求的场景，`unordered_map`则适用于有查找需求的场景，因为`unordered_map`的查找是 $O(1)$ 的，`map`则是 $O(log n)$ 的。