//https://www.luogu.com.cn/problem/P1601
#include <iostream>
#include <cstring>
using namespace std;
char a1[100001], b1[100001];
int a[100001], b[100001], c[100001], lena, lenb, lenc, in = 0;
int main(){
    cin >> a1 >> b1;
    lena = strlen(a1), lenb = strlen(b1), lenc = max(lena, lenb);
    for(int i = 0; i < lena; i++) a[i] = a1[lena - 1 - i] - '0';
    for(int i = 0; i < lenb; i++) b[i] = b1[lenb - 1 - i] - '0';
    for(int i = 0; i < lenc; i++){
        c[i] = a[i] + b[i] + in;
        in = c[i] / 10;
        c[i] %= 10;
    }
    if(in != 0){
        c[lenc] = in;
        lenc++;
    }
    for(int i = 0; i < lenc; i++) cout << c[lenc - 1 - i];
    return 0;
}