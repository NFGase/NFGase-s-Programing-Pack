//https://www.luogu.com.cn/problem/P1303
#include <iostream>
#include <cstring>
using namespace std;
char a[2001], b[2001];
int a1[2001] = {}, b1[2001] = {}, c[100000]= {};
int main(){
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b);
    for(int i = lena - 1; i >= 0; i--) a1[i] = a[lena - 1 - i] - '0';
    for(int i = lenb - 1; i >= 0; i--) b1[i] = b[lenb - 1 - i] - '0';
    for(int j = 0; j < lenb; j++){
        int in = 0;
        for(int i = 0; i < lena; i++){
            c[i + j] = (a1[i] * b1[j]) + in + c[i + j];
            in = c[i + j] / 10;
            c[i + j] %= 10;
        }
        c[lena + j] = in;
    }
    int lenc = lena + lenb;
    while(c[lenc - 1] == 0 && lenc > 1) lenc--;
    for(int i = lenc - 1; i >= 0; i--) cout << c[i];
    return 0;
}