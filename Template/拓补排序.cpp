#include <iostream>
#include <queue>
int n, x, in[10001], len[100001], maps[1001][1001];
std::queue <int> que;
int main(){
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        while(std::cin >> x){
            if(x == 0) break;
            maps[i][++len[i]] = x;
            in[x]++;
        }
    }
    for(int i = 1; i <= n; i++) if(in[i] == 0) que.push(i);
    for(int i = 1; i <= n; i++){
        int x = que.front();
        std::cout << x << " ";
        que.pop();
        for(int j = 1; j <= len[x]; j++){
            in[maps[x][j]]--;
            if(in[maps[x][j]] == 0) que.push(maps[x][j]);
        }
    }
    return 0;
}