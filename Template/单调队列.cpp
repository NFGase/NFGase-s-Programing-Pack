//https://www.luogu.com.cn/problem/P1886
#include <iostream>
#include <deque>
using namespace std;
long long n, k, a[1000001], mi[1000001], mx[1000001];
deque <long long> deq;
signed main(){
    cin >> n >> k;
    for(register long long i = 1; i <= n; i++) cin >> a[i];
    for(long long i = 1; i <= n; i++){ //区间最小
        while(deq.empty() == false && deq.front() < i - k + 1) deq.pop_front();
        while(deq.empty() == false && a[deq.back()] >= a[i]) deq.pop_back();
        deq.push_back(i);
        if(i >= k) cout << a[deq.front()] << " ";
    }
    deq.clear();
    cout << endl;
    for(long long i = 1; i <= n; i++){ //区间最大值
        while(deq.empty() == false && deq.front() < i - k + 1) deq.pop_front();
        while(deq.empty() == false && a[deq.back()] <= a[i]) deq.pop_back();
        deq.push_back(i);
        if(i >= k) cout << a[deq.front()] << " ";
    }
    return 0;
}