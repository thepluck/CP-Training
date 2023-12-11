#include <bits/stdc++.h>
using namespace std;

int led[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int lar[] = {1, 5, 1, 2, 2, 3, 1, 2, 0, 0};
int num[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
int dgt[25];

int main(){
    freopen("LED.inp", "r", stdin);
    freopen("LED.out", "w", stdout);
    int type; long long n; cin >> type >> n;
    if (type == 1){
        if (type == 0) return cout << 6 << '\n', 0;
        int res = 0;
        while (n > 0){
            res += led[n % 10]; n /= 10;
        }
        return cout << res << '\n', 0;
    }
    if (n == 0) return cout << 1 << '\n', 0;
    int cnt = 0;
    while (n > 0){
        dgt[cnt++] = n % 10; n /= 10;
    }
    reverse(dgt, dgt + cnt);
    long long res = 0;
    for (int i = 0; i < cnt; i++){
        long long tmp = lar[dgt[i]];
        for (int j = i + 1; j < cnt; j++)
            tmp *= num[dgt[j]];
        res += tmp;
    }
    cout << res << '\n';
}