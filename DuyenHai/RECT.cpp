#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll res[305][305]; int a[305][305];
int temp[305];

int main(){
    int n, m; cin >> n >> m; 
    temp[0] = temp[m + 1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= m; x++) temp[x] = 0;
        for (int j = i; j <= n; j++){
            bool flag = false; int prev;
            for (int x = 1; x <= m; x++){
                temp[x] |= a[j][x];
                if (!temp[x]) flag = true;
            }
            if (!flag) break;
            for (int x = 1; x <= m; x++){
                if (temp[x] == 0 && temp[x - 1] == 1)
                    prev = x;
                if (temp[x] == 0 && temp[x + 1] == 1){
                    for (int y = prev; y <= x; y++)
                        res[j - i + 1][y - prev + 1] += x - y + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << res[i][j] << " \n"[j == m];
}