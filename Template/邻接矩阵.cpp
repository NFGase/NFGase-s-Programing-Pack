#include <iostream>
using namespace std;
int n, m;
bool mark[1001][1001];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        mark[x][y] = true, mark[y][x] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << mark[i][j] << " ";
        cout << endl;
    }
    return 0;
}