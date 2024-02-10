// https://www.luogu.com.cn/problem/P3374
// https://www.luogu.com.cn/problem/P3368
#include <iostream>
namespace io{
    template <typename T> inline void read(T& x){x = 0; bool f = false; char ch = getchar(); while(ch < '0' || ch > '9'){if(ch == '-') f = !f; ch = getchar();}while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();} x = (f ? -x : x); return;}
    template <typename T, typename... Args> inline void read(T& x, Args&...x_){read(x), read(x_...);}
    template <typename T> inline void put(T x){if(x < 0) putchar('-'), x = -x; if(x > 9) put(x / 10); putchar(x % 10 + '0'); return ;}
    template <typename T> inline void write(T x){put(x);}
    template <typename T, typename... Args> inline void write(T x, Args...x_){write(x), write(x_...);}
    inline void newb(){putchar(' ');}
}
namespace P3374{
    int n, m, TreeArray[1000001], cnt = 0;
    int lowbit(int x){return x & (-x);}
    void add_TreeArray_point(int x, int v){for(int i = x; i <= n; i += lowbit(i)) TreeArray[i] += v;}
    void TreeArraySum(int a, int b){
        for(int i = b; i >= 1; i -= lowbit(i)) cnt += TreeArray[i];
        for(int i = a - 1; i >= 1; i -= lowbit(i)) cnt -= TreeArray[i];
    }
    int main(){
        io::read(n, m);
        for(int i = 1; i <= n; i++){
            int x;
            io::read(x);
            add_TreeArray_point(i, x);
        }
        for(int i = 1; i <= m; i++){
            int option, x, y;
            io::read(option, x, y);
            if(option == 1) add_TreeArray_point(x, y);
            else if(option == 2){
                cnt = 0;
                TreeArraySum(x, y);
                io::write(cnt), puts("");
            }
        }
        return 0;
    }
}
namespace P3368{
    long long n, m, TreeArray[1000001], cnt = 0, a[1000001], b[1000001], ans = 0;
    long long lowbit(long long x){return x & (-x);}
    void add_TreeArray_point(long long x, long long v){for(long long i = x; i <= n; i += lowbit(i)) TreeArray[i] += v;}
    long long TreeArrayAllSum(long long x){
        for(long long i = x; i >= 1; i -= lowbit(i)) ans += TreeArray[i];
        return ans;
    }
    int main(){
        std::cin >> n >> m;
        for(long long i = 1; i <= n; i++) std::cin >> a[i];
        for(long long i = 1; i <= m; i++){
            long long option;
            std::cin >> option;
            if(option == 1){
                long long x, y, k;
                std::cin >> x >> y >> k;
                add_TreeArray_point(x, k);
                add_TreeArray_point(y + 1, -k);
            }
            else if(option == 2){
                long long x;
                std::cin >> x;
                ans = 0;
                std::cout << a[x] + TreeArrayAllSum(x) << std::endl;
            }
        }
        return 0;
    }
}
namespace code{
    int main(){
        P3374::main();
        P3368::main();
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}