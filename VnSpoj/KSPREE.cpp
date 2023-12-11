#include <bits/stdc++.h>
using namespace std;

int a[50], n, dp[1 << 21];

bool get_bit(int msk, int pos){
    return msk >> pos & 1;
}

void off_bit(int &msk, int pos){
    msk &= ~(1 << pos);
}

int calc(int msk, int rst){
    if (dp[msk] != -1) return dp[msk]; 
    if (rst == 0) return dp[msk] = 0;
    dp[msk] = INT_MAX;
    for (int i = 0; i < n; i++) 
        if (get_bit(msk, i)){
            int dif = 0, nmsk = msk;
            for (int v = -1; v <= 1; v++)
                if (get_bit(msk, (i + v + n) % n)){
                    dif += a[(i + v + n) % n]; 
                    off_bit(nmsk, (i + v + n) % n);
                }
            dp[msk] = min(dp[msk], calc(nmsk, rst - dif) + rst - dif);
        }
    return dp[msk];
}

int main(){
    memset(dp, -1, sizeof dp);
    int sum = 0; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i]; sum += a[i];
    }
    cout << calc((1 << n) - 1, sum) << '\n';
}