// https://www.luogu.com.cn/problem/P1048
#include <iostream>
#include <cstdio>
using namespace std;
int m, n, a[10001], b[10001], dp[1001][1001];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(j < a[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + b[i]);
        }
    }
    cout << dp[m][n];
    return 0;
}