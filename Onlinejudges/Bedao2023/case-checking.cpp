#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
 
int n;
int a[N];
 
char choose[N];
 
int cntpmax;
int pmax[N];
int idxpmax[N];
 
int lis;
pair <int, int> tmpdp[2 * N];
 
int dp[N], trace[N];
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int tests; cin >> tests; while (tests--){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
 
    cntpmax = 0;
    int mx = numeric_limits <int>::min();
    for (int i = 1; i <= n; i++){
        if (mx < a[i]){
            mx = a[i];
            cntpmax++;
            pmax[cntpmax] = i;
            idxpmax[i] = cntpmax;
        }
        else{
            idxpmax[i] = -1;
        }
    }
 
    if (cntpmax % 2 == 0){
        for (int i = 1; i <= n; i++){
            choose[i] = 'M';
        }
        for (int i = 1; i <= n; i++){
            if (idxpmax[i] == cntpmax / 2 + 1){
                break;
            }
            choose[i] = 'D';
        }
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++){
            cout << choose[i];
        } cout << '\n';
        continue;
    }
 
    bool ans = false;
    int curpmax = 0;
    for (int i = 1; i <= n; i++){
        if (idxpmax[i] != -1){
            curpmax++;
            continue;
        }
        if (curpmax <= cntpmax / 2 + 1){
            for (int j = 1; j <= n; j++){
                choose[j] = 'M';
            }
            for (int j = 1; j <= n; j++){
                if (idxpmax[j] == cntpmax / 2 + 2){
                    break;
                }
                choose[j] = 'D';
            }
            choose[i] = 'M';
            ans = true;
            break;
        }
        else{
            if (a[i] > a[pmax[curpmax - (cntpmax / 2 + 1)]]){
                for (int j = 1; j <= n; j++){
                    choose[j] = 'M';
                }
                int tcurpmax = 0;
                for (int j = 1; j <= n; j++){
                    if (idxpmax[j] != -1){
                        tcurpmax++;
                    }
                    if (curpmax - (cntpmax / 2 + 1) < tcurpmax and tcurpmax <= curpmax){
                        choose[j] = 'D';
                    }
                }
                choose[i] = 'M';
                ans = true;
                break;
            }
        }
    }
    if (ans){
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++){
            cout << choose[i];
        } cout << '\n';
        continue;
    }
 
    lis = 0;
    tmpdp[lis] = make_pair(numeric_limits <int>::min(), 0);
    for (int i = 1; i <= n; i++){
        if (idxpmax[i] != -1){
            continue;
        }
        dp[i] = upper_bound(tmpdp, tmpdp + lis + 1, make_pair(a[i], numeric_limits <int>::max())) - tmpdp;
        if (dp[i] == lis + 1){
            lis++;
        }
        trace[i] = tmpdp[dp[i] - 1].second;
        tmpdp[dp[i]] = make_pair(a[i], i);
 
        if (lis == cntpmax){
            for (int j = 1; j <= n; j++){
                choose[j] = 'M';
            }
            while (i != 0){
                choose[i] = 'D';
                i = trace[i];
            }
            ans = true;
            break;
        }
    }
    if (ans){
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++){
            cout << choose[i];
        } cout << '\n';
        continue;
    }
 
    cout << "NO" << endl;
}
}
