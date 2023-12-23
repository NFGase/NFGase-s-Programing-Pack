// https://www.luogu.com.cn/problem/P4779
#include <iostream>
#include <limits>
#include <queue>
namespace io{
    template <typename T> inline void read(T& x){x = 0; bool f = false; char ch = getchar(); while(ch < '0' || ch > '9'){if(ch == '-') f = !f; ch = getchar();}while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();} x = (f ? -x : x); return ;}
    template <typename T, typename... Args> inline void read(T& x, Args&...x_){read(x), read(x_...);}
    template <typename T> inline void put(T x){if(x < 0) putchar('-'), x = -x; if(x > 9) put(x / 10); putchar(x % 10 + '0'); return ;}
    template <typename T> inline void write(T x){put(x);}
    template <typename T, typename... Args> inline void write(T x, Args...x_){write(x), write(x_...);}
    inline void newb(){putchar(' ');}
}
namespace code{
    long long n, m, s, dp[1000001], now, mi = std::numeric_limits <int>::max(), cnt = 1, head[1000001];
    bool vis[1000001];
    std::priority_queue <std::pair <int, int>> pri_que;
    struct node{int num, w, next;}edge[1000001];
    void add_edge(int u, int v, int w){
        edge[cnt].num = v;
        edge[cnt].w = w;
        edge[cnt].next = head[u];
        head[u] = cnt++;
    }
    int main(){
        std::cin >> n >> m >> s;
        now = s;
        for(int i = 1; i <= n; i++) dp[i] = mi;
        pri_que.push(std::make_pair(0, s));
        while(m--){
            int u, v, w;
            std::cin >> u >> v >> w;
            add_edge(u, v, w);
        }
        dp[s] = 0;
        while(pri_que.empty() == false){
            std::pair <int, int> start = pri_que.top();
            int x = start.second, y = -start.first;
            pri_que.pop();
            if(y == dp[x]){
                for(int i = head[x]; i != 0; i = edge[i].next){
                    int a = edge[i].num, b = edge[i].w;
                    if(dp[a] > dp[x] + b){
                        dp[a] = dp[x] + b;
                        pri_que.push(std::make_pair(-dp[a], a));
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++) std::cout << dp[i], io::newb();
        return 0;
    }
}
int main(){
    code::main();
    return 0;
}