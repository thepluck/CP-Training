#include <bits/stdc++.h>
using namespace std;
string s[70] , t;
int n ,m ,f[70][70] ,p;

int main(){
    cin >> p >> m >> n >> t;
    for (int i = 1 ; i <= m ; ++i){
        cin >> s[i]; s[i] = ' ' + s[i];
    }
    if (p == 1){
        int d = 0;
        for (int i = 1; i <= m ; i++)
            for (int j = 1; j <= n ; j++){
                bool flag = isalpha(s[i][j]);
                f[i][j] = flag + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
                d += flag;
        }
        int ans = n * m;
        for (int i = 1; i <= m ; i++)
            for (int j = 1; j <= n ; j++)
                for (int k = i; k <= m ; k++)
                    for (int l = j; l <= n ; l++)
                        if (f[k][l] - f[i - 1][l] - f[k][j - 1] + f[i - 1][j - 1] == d) 
                            ans = min(ans, (k - i + 1) * (l - j + 1));
        cout << ans;
    }
}