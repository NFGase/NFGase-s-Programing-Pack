//https://www.luogu.com.cn/problem/P5788
#include <iostream>
#include <stack>
using namespace std;
long long n, a[10000001], ans[10000001];
stack <long long> sta;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(register long long i = 1; i <= n; i++) cin >> a[i];
    for(register long long i = n; i >= 1; i--){
        while(sta.empty() == false && a[sta.top()] <= a[i]) sta.pop();
        if(sta.empty() == false) ans[i] = sta.top();
        else ans[i] = 0;
        sta.push(i);
    }
    for(register long long i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}