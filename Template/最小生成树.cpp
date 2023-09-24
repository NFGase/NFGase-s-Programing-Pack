//https://www.luogu.com.cn/problem/P1546
#include <iostream>
#include <climits>
using namespace std;
int n, a[1001][1001], dis[100001], ans = 0, cnt = 1;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
    for(int i = 0; i < n; i++) dis[i] = a[0][i];
    while(cnt < n){
        int id = 0, min_dis = INT_MAX;
        for(int i = 0; i < n; i++){
            if(dis[i] != 0){
                if(min_dis > dis[i]){
                    min_dis = dis[i];
                    id = i;
                }
            }
        }
        for(int i = 0; i < n; i++) dis[i] = min(dis[i], a[id][i]);
        ans += min_dis;
        cnt++;
    }
    cout << ans;
    return 0;
}