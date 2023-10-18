#include <iostream>
using namespace std;
// io::read(x1);输入，可以输入多个数字，如io::read(a, b, c);，类型可为int，也可为long long；
// io::write(x1);输出，可以输出多个数字，如io::write(a, b, c);，类型可为int，也可为long long；
// io::newb();，输出空格，new blank的缩写，本质是putchar快速输出一个空格；
// io::newl();，输出换行，new line的缩写，本质是利用puts("");超快输出字符串时自带一个换行的特性来输出一个空字符串的同时输出一个换行；
// puts("");，输出字符串，C++自带，和cout << "";类似，只不过比后者更快。
namespace io{
    template <typename T> inline void read(T& x){x = 0; bool f = false; char ch = getchar(); while(ch < '0' || ch > '9'){if(ch == '-') f = !f; ch = getchar();}while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();} x = (f ? -x : x); return;}
    template <typename T, typename... Args> inline void read(T& x, Args&...x_){read(x), read(x_...);}
    template <typename T> inline void put(T x){if(x < 0) putchar('-'), x = -x; if(x > 9) put(x / 10); putchar(x % 10 + '0'); return ;}
    template <typename T> inline void write(T x){put(x);}
    template <typename T, typename... Args> inline void write(T x, Args...x_){write(x), write(x_...);}
    inline void newb(){putchar(' ');}
    inline void newl(){puts("");}
}
long long a, b;
int main(){
    io::read(a, b); // 输入a, b
    io::write(a); // 输出a
    io::newb(); // 输出空格
    io::write(b); // 输出b
    io::newl(); // 输出换行
    io::write(a + b); // 输出a + b
    // 所以如果输入1 2，则输出
    // 1 2
    // 3
    return 0;
}