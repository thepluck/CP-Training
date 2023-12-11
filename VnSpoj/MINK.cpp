#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int a[N], n, k; deque <int> dq;

void solve(){
    scanf("%d%d", &n, &k); dq.clear();
    for (int i = 0; i < n; i++) 
        scanf("%d", a + i);
    for (int i = 0; i < k; i++){
        while (!dq.empty() && a[dq.back()] >= a[i]) 
            dq.pop_back();
        dq.push_back(i);
    }
    printf("%d ", a[dq.front()]);
    for (int i = k; i < n; i++){
        while (!dq.empty() && dq.front() <= i - k) 
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] >= a[i]) 
            dq.pop_back();
        dq.push_back(i);
        printf("%d ", a[dq.front()]);
    }
    putchar('\n');
}

int main(){
    int test; cin >> test;
    while (test--) solve();
}