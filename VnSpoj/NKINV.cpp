#include <bits/stdc++.h>
using namespace std;
int a[int(1e5)], bit[int(1e5)];
int n, kq = 0;

void update(int i){
    for (; i <= 1e5; i += i & -i) bit[i]++;
}

int get(int i){
    int ans = 0;
    for (; i > 0; i -= i & -i) ans += bit[i];
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(bit, 0, sizeof bit); cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 0; i--){
        kq += get(a[i]);
        update(a[i] + 1);
    }
    cout << kq;
}
