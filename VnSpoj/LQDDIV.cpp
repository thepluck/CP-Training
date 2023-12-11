//
//  main.cpp
//  LQDDIV - Phân tập
//  https://vn.spoj.com/problems/LQDDIV/
//  Created by Trần Dũng on 9/14/19.
//  Copyright © 2019 Trần Dũng. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = (1 << 16);
int a[35];
int n;
int l[maxn], r[maxn];

bool getBit(int i, int j){
    return (i >> (j - 1)) & 1;
}

void preCount(int n, int id, int arr[]){
    for (int i = 0; i < (1 << n); i++){
        int sum = 0;
        for (int j = 1; j <= n; j++){
            if (getBit(i, j)){
                sum += a[id + j];
            }
        }
        arr[i] = sum;
    }
}
int main() {
    cin >> n;
    int total = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        total += a[i];
    }
    int n1, n2;
    n1 = n >> 1;
    n2 = n - n1;
    preCount(n1, 0, l);
    preCount(n2, n1, r);
    sort(r, r + (1 << n2));

    int ans = 1e9;
    int ct = 0;
    for (int i = 0; i < (1 << n1); i++){
        int lo = 0;
        int hi = (1 << n2) - 1;
        int res = 0;
        while (lo <= hi){
            int mid = (lo + hi) >> 1;
            if (l[i] + r[mid] <= (total >> 1)){
                res = mid;
                lo = mid + 1;
            }else hi = mid - 1;
        }
        int x, y;
        x = y = res;
        while (r[x - 1] == r[res] && x >= 1) x--;
        while (r[y + 1] == r[res] && y < (1 << n2) - 1) y++;
        int tmp = total - 2 * (l[i] + r[res]);
        if (tmp >= 0){
            if (tmp == ans){
                ct += (y - x + 1);
            }
            if (tmp < ans){
                ans = tmp;
                ct = (y - x + 1);
            }
        }
    }
    if (ans == 0) ct /= 2;
    cout << ans << " " << ct << endl;
    return 0;
}
