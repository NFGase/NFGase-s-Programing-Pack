// 题目描述
// 约翰是一名牛奶运输员，他每天的工作就是向德克萨斯州的每个城镇运送大量的牛奶，由于运输过程中会有一些费用的产生，约翰想知道自己从某个城镇到另一个城镇的最小总费用。德克萨斯州一共包含n个城镇，为了方便运输，约翰将城镇编号为1到n，有的城镇之间有双向的公路，有的城镇之间则没有，每条公路有一个通过费用（包括油费、过路费等），给定一个地图，包含m条直接连接2个城镇的公路，每条公路由起点s，终点e和通过费用c组成。求从起始城镇a到终点城镇b的最小总费用。

// 输入描述
// 输入文件名 milk.in。

// 第一行：包含四个正整数n，m，a，b，分别表示n个城镇，m条公路，起点城镇a和终点城镇b

// 第二行到第m + 1行：第i+1行描述第i条公路，包含3个正整数s，e，c，分别表示公路起点s，公路终点e和通过费用c。

// 输出描述
// 输出文件名 milk.out。

// 一个正整数，表示从城镇a到城镇b的最小总费用。

// 样例1
// 输入
// 5 6 5 4
// 1 4 3
// 3 4 3
// 2 4 3
// 2 3 1
// 3 5 5
// 1 5 1
// 输出
// 4
// 提示
// 对于100%的数据，1 <= n <= 100，1 <= m <= 500，1 <= s，e，a，b <= n，1 <= c <= 1000
#include <iostream>
namespace io{
    template <typename T> inline void read(T& x){x = 0; bool f = false; char ch = getchar(); while(ch < '0' || ch > '9'){if(ch == '-') f = !f; ch = getchar();}while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();} x = (f ? -x : x); return;}
    template <typename T, typename... Args> inline void read(T& x, Args&...x_){read(x), read(x_...);}
    template <typename T> inline void put(T x){if(x < 0) putchar('-'), x = -x; if(x > 9) put(x / 10); putchar(x % 10 + '0'); return ;}
    template <typename T> inline void write(T x){put(x);}
    template <typename T, typename... Args> inline void write(T x, Args...x_){write(x), write(x_...);}
    inline void newb(){putchar(' ');}
}
namespace code{
    int n, m, a, b, dp[1001][1001];
    int main(){
        std::cin >> n >> m >> a >> b;
        for(int i = 1; i <= n; i++) dp[i][i] = 0;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] = 1145;
        while(m--){
            int s, e, c;
            std::cin >> s >> e >> c;
            dp[s][e] = c, dp[e][s] = c;
        }
        for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
        std::cout << dp[a][b];
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}