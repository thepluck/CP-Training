#include <bits/stdc++.h>
using namespace std;

int max_palin(const string &s){
    string t; for (char c : s) t += "#", t += c;
    t += "#"; int n = t.size();
    vector <int> f(n); int c(0), r(0);
    for (int i = 0; i < n; i++){
        f[i] = i < r ? min(r - i, f[2 * c - i]) : 0;
        while (i > f[i] && i + f[i] + 1 < n)
            if (t[i - f[i] - 1] == t[i + f[i] + 1]) f[i]++;
            else break;
        if (i + f[i] > r){
            c = i; r = i + f[i];
        }
    }
    return *max_element(f.begin(), f.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; string s; cin >> n >> s;
    cout << max_palin(s) << '\n';
}