#include <bits/stdc++.h>
using namespace std;

int  main(){
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    int f[n + 2][n + 2];
    for (int i = 0; i <= n + 1; i++){
        f[0][i] = 0; f[i][n + 1] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= 1; j--){
            if (s[i] == s[j]) f[i][j] = f[i - 1][j + 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j + 1]);
        }
    int i = n, j = 1;
    string ans;
    while (i >= 1 && j <= n){
        if (s[i] == s[j]){
            ans += s[i]; i--; j++;
        }
        else if (f[i][j] == f[i - 1][j]) i--;
        else j++;
    }
    cout << ans;
}
