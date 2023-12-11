#include <bits/stdc++.h>
using namespace std;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (auto &x : a) cin >> x;
    ll sum = 0, res;
    int cntodd, cnteven;
    cntodd = cnteven = 0;
    for (int i = 0; i < k; i++){
        sum += a[i];
        if (a[i] & 1) cntodd++;
        else cnteven++;
    }
    if (cntodd && cnteven) res = sum;
    for (int i = k; i < n; i++){
        sum += a[i] - a[i - k];
        if (a[i - k] & 1) cntodd--;
        else cntodd++;
        if (cntodd && cnteven) chkmin(res, sum);
    }
    cout << res << endl; return 0;
}