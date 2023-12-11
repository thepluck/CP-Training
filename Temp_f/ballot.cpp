#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector <int> a; int n, b;
    while (cin >> n >> b){
        if (n == -1) break; a.resize(n);
        for (int &x : a) cin >> x;
        int lo = 1, hi = 5e5 + 5, mi, res;
        while (lo <= hi){
            int cnt = 0;
            mi = (lo + hi) / 2;
            for (int x : a)
                cnt += (x - 1) / mi + 1;
            if (cnt <= b)
                res = mi, hi = mi - 1;
            else lo = mi + 1;
        }
        cout << res << '\n';
    }
}