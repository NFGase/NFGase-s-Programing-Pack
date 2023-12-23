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
    int n, m, q, a[100001], cnt = 0;
    bool marks[1001][1001], vis[100001];
    void dfs(int spot){
        std::cout << spot, io::newb();
        cnt++;
        if(cnt == n) return ;
        for(int i = 1; i <= n; i++){
            if(vis[i] == false && (marks[spot][i] == true || marks[i][spot] == true)){
                vis[i] = true;
                dfs(i);
            }
        }
    }
    int main(){
        std::cin >> n >> m;
        while(m--){
            int x, y;
            std::cin >> x >> y;
            marks[x][y] = true, marks[y][x] = true;
        }
        vis[1] = true;
        dfs(1);
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}