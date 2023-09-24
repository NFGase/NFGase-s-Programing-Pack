#include <iostream>
using namespace std;
int n, m, q, a[100001], cnt = 0;
bool marks[1001][1001], vis[100001];
void dfs(int spot){
    cout << spot << " ";
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
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        marks[x][y] = true, marks[y][x] = true;
    }
    vis[1] = true;
    dfs(1);
    return 0;
}