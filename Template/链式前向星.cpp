#include <iostream>
using namespace std;
struct Edge{int to, w, next;}edge[100001];
int head[100001], n, m, cnt = 0;
void init(){
    for(int i = 1; i <= n; i++) head[i] = -1;
    cnt = 0;
}
void add_edge(int u, int v, int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int main(){
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    for(int i = 1; i <= n; i++){
        cout << i << endl;
        for(int j = head[i]; j != -1; j = edge[j].next) cout << i << " " << edge[j].to << " " << edge[j].w << endl;
        puts("");
    }
    return 0;
}
