//https://www.luogu.com.cn/problem/P2142
#include <iostream>
#include <cstring>
using namespace std;
char a1[100001], b1[100001];
int a[100001], b[100001], c[200002], lena, lenb, lenc;
int main(){
    cin >> a1 >> b1;
    lena = strlen(a1), lenb = strlen(b1), lenc = max(lena, lenb);
    if(lena < lenb || (lena == lenb && strcmp(a1, b1) < 0)){
        cout << "-";
        swap(lena, lenb);
        swap(a1, b1);
    }
    for(int i = 0; i < lena; i++) a[i] = a1[lena - 1 - i] - '0';
    for(int i = 0; i < lenb; i++) b[i] = b1[lenb - 1 - i] - '0';
    for(int i = 0; i < lenc; i++){
        if(a[i] < b[i]){
            a[i] += 10;
            a[i + 1]--;
        }
        c[i] = a[i] - b[i];
    }
    while(c[lenc - 1] == 0 && lenc > 1) lenc--;
    for(int i = 0; i < lenc; i++) cout << c[lenc - 1 - i];
    return 0;
}