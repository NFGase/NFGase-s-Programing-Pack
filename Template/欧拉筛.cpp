#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    int a[1000001] = {};
    int su[1000001] = {};
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] == 0) su[cnt++] = i;
        for(int j = 0; j < cnt && su[j] * i <= n; j++){
            a[su[j] * i] = 1;
            if(i % su[j] == 0) break;
        }
    }
    for(int i = 2; i <= n; i++) if(a[i] == 0) cout << i << " ";
    return 0;
}