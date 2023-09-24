#include <iostream>
#include <algorithm>
using namespace std;
long long n, a[100001], b[100001];
void Merge_Sort(long long l, long long r){
    if(l >= r) return ;
    long long mid = (l + r) / 2;
    Merge_Sort(l, mid);
    Merge_Sort(mid + 1, r);
    long long i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int q = l; q <= r; q++) a[q] = b[q];
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Merge_Sort(1, n);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}