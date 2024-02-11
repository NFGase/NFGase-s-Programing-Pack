// https://www.luogu.com.cn/problem/P1919
#include <iostream>
#include <complex>
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
    const double pi = acos(-1);
    int n, m, lim, r[10000001], cnt = 0, rev[10000001], res[10000001], bit, tot, top, l = 0;
    std::string s1, s2;
    std::complex <double> a[10000001], b[10000001];
    void FastFourierTransform(std::complex <double> * a, int option){
        for(int i = 0; i < lim; i++) if(i < r[i]) swap(a[i], a[r[i]]);
        for(int i = 1; i < lim; i <<= 1){
            std::complex <double> x(cos(pi / i), option * sin(pi / i));
            for(int j = 0; j < lim; j += (i << 1)){
                std::complex <double> y(1, 0);
                for(int k = 0; k < i; k++, y *= x){
                    std::complex <double> t = a[j + k], s = a[i + j + k] * y;
                    a[j + k] = t + s;
                    a[i + j + k] = t - s;
                }
            }
        }
    }
    int main(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cin >> s1 >> s2;
        n = s1.length() - 1, m = s2.length() - 1;
        for(int i = 0; i <= n; i++) a[i] = s1[n - i] - '0';
        for(int i = 0; i <= m; i++) b[i] = s2[m - i] - '0';
        for(lim = 1; lim <= (n + m); lim <<= 1) cnt++;
        for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
        FastFourierTransform(a, 1), FastFourierTransform(b, 1);
        for(int i = 0; i <= lim; i++) a[i] *= b[i];
        FastFourierTransform(a, -1);
        for(int i = 0; i <= (n + m); i++) res[i] = (int)(0.5 + a[i].real() / lim);
        top = n + m;
        while(l <= top){
            if(res[l] >= 10){
                res[l + 1] += res[l] / 10;
                top += l == top;
                res[l] %= 10;
            }
            l++;
        }
        while(res[top] == 0 && top > 0) top--;
        for(int i = top; i >= 0; i--) std::cout << res[i];
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}