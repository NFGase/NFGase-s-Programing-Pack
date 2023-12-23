//https://www.luogu.com.cn/problem/P3375
#include <iostream>
#include <string>
namespace io{
    template <typename T> inline void read(T& x){x = 0; bool f = false; char ch = getchar(); while(ch < '0' || ch > '9'){if(ch == '-') f = !f; ch = getchar();}while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();} x = (f ? -x : x); return;}
    template <typename T, typename... Args> inline void read(T& x, Args&...x_){read(x), read(x_...);}
    template <typename T> inline void put(T x){if(x < 0) putchar('-'), x = -x; if(x > 9) put(x / 10); putchar(x % 10 + '0'); return ;}
    template <typename T> inline void write(T x){put(x);}
    template <typename T, typename... Args> inline void write(T x, Args...x_){write(x), write(x_...);}
    inline void newb(){putchar(' ');}
}
namespace code{
    int kmp[100001], len1, len2, j = 0;
    std::string s1, s2;
    int main(){
        std::cin >> s1 >> s2;
        len1 = s1.length(), len2 = s2.length();
        kmp[0] = 0, kmp[0] = 1;
        for(int i = 1; i < len2; i++){
            while(j != 0 && s2[i] != s2[j]) j = kmp[j];
            kmp[i + 1] = s2[i] == s2[j] ? ++j : 0;
        }
        j = 0;
        for(int i = 0; i < len1; i++){
            while(j != 0 && s1[i] != s2[j]) j = kmp[j];
            j += s1[i] == s2[j] ? 1 : 0;
            if(j == len2) std::cout << i - len2 + 2, puts("");
        }
        for(int i = 1; i <= len2; i++) std::cout << kmp[i], io::newb();
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}