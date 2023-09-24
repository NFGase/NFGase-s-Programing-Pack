#include <iostream>
using namespace std;
long long n, a[100001];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        int mi = i;
        for(int j = i + 1; j <= n; j++) if(a[j] < a[mi]) mi = j;
        swap(a[i], a[mi]);
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}