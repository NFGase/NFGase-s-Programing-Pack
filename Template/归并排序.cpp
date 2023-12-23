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
    long long n, a[100001], b[100001];
    void Merge_Sort(long long l, long long r){
        if(l >= r) return ;
        long long mid = (l + r) / 2;
        Merge_Sort(l, mid);
        Merge_Sort(mid + 1, r);
        long long i = l, j = mid + 1, k = l;
        while(i <= mid && j <= r){
            if(a[i] <= a[j]) b[k++] = a[i++];
            else b[k++] = a[j++];
        }
        while(i <= mid) b[k++] = a[i++];
        while(j <= r) b[k++] = a[j++];
        for(int q = l; q <= r; q++) a[q] = b[q];
    }
    int main(){
        std::cin >> n;
        for(int i = 1; i <= n; i++) std::cin >> a[i];
        Merge_Sort(1, n);
        for(int i = 1; i <= n; i++) std::cout << a[i], io::newb();
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}