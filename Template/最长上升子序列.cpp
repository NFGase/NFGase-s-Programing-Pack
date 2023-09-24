//https://www.luogu.com.cn/problem/B3637
#include <iostream>
using namespace std;
int n, a[100001], dp[100001], mx = -1;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], dp[i] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++) if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
    for(int i = 1; i <= n; i++) mx = max(mx, dp[i]);
    cout << mx;
    return 0;
}