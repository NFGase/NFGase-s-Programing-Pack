//https://www.luogu.com.cn/problem/P1439
#include <iostream>
#include <climits>
using namespace std;
long long n, a[10000001], b[10000001], c[1000001], maps[100001], x = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    c[0] = 0;
    for(register int i = 1; i <= n; i++){
        cin >> a[i];
        maps[a[i]] = i;
    }
    for(register int i = 1; i <= n; i++){
        cin >> b[i];
        c[i] = INT_MAX;
    }
    for(register int i = 1; i <= n; i++){
        int left = 0, right = x, mid = (left + right) >> 1;
        if(maps[b[i]] > c[x]) c[++x] = maps[b[i]];
        else{
            while(left < right){
                mid = (left + right) >> 1;
                if(c[mid] > maps[b[i]]) right = mid;
                else left = mid + 1;
            }
            c[left] = min(maps[b[i]], c[left]);
        }
    }
    cout << x;
    return 0;
}