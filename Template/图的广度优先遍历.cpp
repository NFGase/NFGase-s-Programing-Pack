#include <iostream>
#include <queue>
using namespace std;
int n, m;
bool mark[1001][1001], vis[10001];
void bfs(){
    queue <int> que;
    int qaq = 1;
    que.push(qaq);
    cout << 1 << " ";
    while(que.empty() == false){
        int x = que.front();
        que.pop();
        for(int i = 1; i <= n; i++){
            if(mark[x][i] == true && vis[i] == false){
                cout << i << " ";
                vis[i] = true;
                que.push(i);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        mark[x][y] = true;
    }
    vis[1] = true;
    bfs();
    return 0;
}