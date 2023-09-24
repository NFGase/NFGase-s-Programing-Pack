//https://www.luogu.com.cn/problem/P1226
#include <iostream>
using namespace std;
long long n, m, x;
long long binary_pow(long long n, long long m){
    if(m == 0) return 1;
    if(m == 1) return n;
    long long ans = binary_pow(n, m / 2) % x;
    if(m % 2 == 0) return (ans % x) * (ans % x) % x;
    else return (((ans % x) * (ans % x)) % x) * (n % x) % x;
}
int main(){
    cin >> n >> m >> x;
    cout << n << "^" << m << " mod " << x << "=" << binary_pow(n, m) % x;
    return 0;
}