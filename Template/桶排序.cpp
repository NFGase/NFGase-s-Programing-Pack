#include <iostream>
#include <cstring>
using namespace std;
int n, a[500000001], m;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m;
		a[m]++;
	}
	for(int i = 1; i <= n; i++) while(a[i]--) cout << i << " ";
	return 0;
}