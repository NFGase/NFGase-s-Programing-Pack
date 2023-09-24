#include <iostream>
using namespace std;
int n, m, v[100005], w[1000005], s[10000005], dp[100005];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
    for(int i = 1; i <= n; i++) for(int j = m; j >= 0; j--) for(int k = 0; k <= s[i] && k * w[i] <= j; k++) dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
    cout << dp[m] << endl;
    return 0;
}