#include <bits/stdc++.h>
using namespace std;

int main(){
    queue <int> q; int res = 0;
    int n, k; cin >> n >> k; q.push(n);
    while (!q.empty()){
        n = q.front(); q.pop();
        if (n <= k || (n - k) & 1) res++;
        else {
            q.push((n - k) >> 1); 
            q.push((n + k) >> 1);
        }
    }
    cout << res << '\n';
}