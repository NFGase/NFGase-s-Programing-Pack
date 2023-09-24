//n进制的m转为a进制
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int c[101], n, a, b, e, g, sum = 0;
string m;
int main(){
    cin >> n >> m >> a;
    int len = m.length();
    for(int i = 0; i < len; i++){
        if(m[i] < 'A'){
            e = pow(n, len - i - 1);
            e *= (m[i] - '0');
            sum += e;
        }
        else{
            e = pow(n, len - i - 1);
            e *= (m[i] - 'A' + 10);
            sum += e;
        }
    }
    while(sum > 0){
        c[g++] = sum % a;
        sum /= a;
    }
    for(int i = g - 1; i >= 0; i--){
        if(c[i] >= 10) cout << char(c[i] + 'A' - 10);
        else cout << c[i];
    }
    return 0;
}