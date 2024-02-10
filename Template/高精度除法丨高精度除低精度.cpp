//https://www.luogu.com.cn/problem/P1480
#include <iostream>
#include <cstring>
using namespace std;
char a1[100001];
long long a[100001] = {}, c[1000002] = {}, b, lena, rem = 0, k = 0;
int main(){
    cin >> a1 >> b;
    lena = strlen(a1);
    if(a1[0] == '0' || b == 0){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < lena; i++) a[i] = a1[i] - '0';
    for(int i = 0; i < lena; i++){
        c[i] = (rem * 10 + a[i]) / b;
        rem = (rem * 10 + a[i]) % b;
    }
    while(c[k] == 0 && k < lena - 1) k++;
    for(int i = k; i < lena; i++) cout << c[i];
    return 0;
}