//https://www.luogu.com.cn/problem/P3375
#include <iostream>
#include <string>
using namespace std;
int kmp[100001], len1, len2, j = 0;
string s1, s2;
int main(){
    cin >> s1 >> s2;
    len1 = s1.length(), len2 = s2.length();
    kmp[0] = 0, kmp[0] = 1;
    for(int i = 1; i < len2; i++){
        while(j != 0 && s2[i] != s2[j]) j = kmp[j];
        kmp[i + 1] = s2[i] == s2[j] ? ++j : 0;
    }
    j = 0;
    for(int i = 0; i < len1; i++){
        while(j != 0 && s1[i] != s2[j]) j = kmp[j];
        j += s1[i] == s2[j] ? 1 : 0;
        if(j == len2) cout << i - len2 + 2 << endl;
    }
    for(int i = 1; i <= len2; i++) cout << kmp[i] << " ";
    return 0;
}