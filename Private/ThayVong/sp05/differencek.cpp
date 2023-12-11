#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define allrev(v) (v).rbegin(), (v).rend()

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
    int n, m, k; cin >> n >> m >> k;
    vector <ll> a(n - k + 1), b(m - k + 1);
    vector <int> input(max(m, n));
    ll sum = 0, res = LLONG_MAX;
    for (int i = 0; i < k; i++){
        cin >> input[i]; 
        sum += input[i];
    } 
    a[0] = sum;
    for (int i = k; i < n; i++){
        cin >> input[i]; 
        sum += input[i] - input[i - k];
        a[i - k + 1] = sum;
    }
    sum = 0;
    for (int i = 0; i < k; i++){
        cin >> input[i]; 
        sum += input[i];
    }
    b[0] = sum;
    for (int i = k; i < m; i++){
        cin >> input[i];
        sum += input[i] - input[i - k];
        b[i - k + 1] = sum;
    }
    sort(all(a)); sort(all(b));
    for (auto x : a){
        //cout << x << ' ';
        auto it = lb(all(b), x);
        if (it != b.end()) chkmin(res, abs(x - *it));
        //cout << it - b.begin() << ' ';
        auto pr = lb(allrev(b), x, greater <ll> ());
        if (pr != b.rend()) chkmin(res, abs(x - *pr));
        //cout << pr - b.rbegin() << '\n';
    }
    cout << res << endl;
}