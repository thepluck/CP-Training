#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], pos[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1, x; i <= n; i++){
        cin >> x; pos[x] = i;
    }
    for (int i = 1; i <= n; i++) 
        a[i] = pos[a[i]];
    int cur = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] >= a[i - 1]) cur++;
        else break;
    cout << n - cur << '\n';
}