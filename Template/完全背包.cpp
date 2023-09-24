#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;
long long n, m, v[10000005], w[10000005], dp[10000005];
int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++) for(int j = 0; j <= m; j++) if(j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[m];
    return 0;
}