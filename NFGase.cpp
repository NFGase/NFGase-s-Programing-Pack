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
    int main(){
        
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}