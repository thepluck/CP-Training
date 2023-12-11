#include <bits/stdc++.h>
using namespace std;

struct manacher{
    vector <int> f;
    manacher(const string &s): f(2 * size(s) + 1){
        string t; for (char c: s) t += '#', t += c;
        t += '#'; int n = t.size(), c(0), r(0);
        for (int i = 0; i < n; i++){
            f[i] = i < r ? min(r - i, f[2 * c - i]) : 0;
            while (i > f[i] && i + f[i] + 1 < n)
                if (t[i - f[i] - 1] == t[i + f[i] + 1]) f[i]++; 
                else break;
            if (i + f[i] > r){
                c = i; r = i + f[i];
            }
        }
    }

    bool is_palin(int i, int j){
        return f[i + j + 1] > j - i;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s; 
    manacher mn(s); int res = 0;
    for (int i = 0; i < size(s); i++){
        int j = 0;
        while (j <= i && mn.is_palin(j, i)){
            res++; j = (j + i) / 2 + 1;
        }
    }
    cout << res << '\n';
}