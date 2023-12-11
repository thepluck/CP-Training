#include <bits/stdc++.h>
using namespace std;

struct Time{
    int x, y;
    bool operator < (const Time& other) const {
        return y < other.y;
    }
};


int main(){
    freopen("select.inp", "r", stdin);
    freopen("select.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector <Time> a(n);
    for (auto &tt : a)
        cin >> tt.x >> tt.y;
    sort(a.begin(), a.end());
    int border = 0, cnt = 0;
    for (auto tt : a){
        if (tt.x >= border){
            border = tt.y; cnt++;
        }
    }
    cout << cnt;
}