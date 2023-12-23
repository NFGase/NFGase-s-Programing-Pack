
#include <iostream>
#include <cstdio>
using namespace std;
long long n, a[100001];
void Fast_Sort(int l, int r){
    if(l >= r) return ;
    int mid = a[l];
    int i = l + 1, j = r;
    while(i <= j){
        while(i <= j && a[i] < mid) i++; 
        while(i <= j && a[j] > mid) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if(a[l] > a[j]) swap(a[l], a[j]);
    Fast_Sort(l, j - 1);
    Fast_Sort(j + 1, r);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Fast_Sort(1, n);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}