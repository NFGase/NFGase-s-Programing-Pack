#include <iostream>
using namespace std;
long long n, a[100001];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        int k = a[i], j;
        for(j = i - 1; j >= 1; j--){
            if(k < a[j]) a[j + 1] = a[j];
            else break;
        }
        a[j + 1] = k;
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}