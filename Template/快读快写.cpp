#include <iostream>
using namespace std;
namespace io{
    inline long long read(){long long x = 0, f = 1; char ch = getchar(); while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();} while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar(); return x * f;}
    inline void write(long long x){if(x < 0) putchar('-'), x = -x; if(x > 9) write(x / 10); putchar(x % 10 + '0'); return ;}
}
long long a, b;
int main(){
    a = io::read(), b = io::read();
    io::write(a + b);
    return 0;
}