#include <bits/stdc++.h>
using namespace std;

const int H = 5e5 + 5;
int trap[2][H];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, h, ans, curr, cnt; 
    cin >> n >> h;
    ans = n + 1; cnt = 0; curr = n / 2;
    for (int i = 0, x; i < n; i++){
        cin >> x; trap[i & 1][x]++;
    }
    for (int i = 1; i <= h; i++){
        if (ans > curr){
            ans = curr; cnt = 1;
        }
        else cnt += ans == curr;
        curr -= trap[0][i];
        curr += trap[1][h - i];
    }
    cout << ans << ' ' << cnt << '\n';
}