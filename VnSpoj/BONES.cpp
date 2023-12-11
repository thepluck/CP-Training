#include <bits/stdc++.h>
using namespace std;

int cnt[100];

int main(){
    int m, n, p; cin >> m >> n >> p;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= p; k++)
                cnt[i + j + k]++;
    cout << max_element(cnt, cnt + 100) - cnt;
}