#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
set <int> active;
map <int, queue <int>> buck;
long long t[N], l[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, id = 0; cin >> n;
    int m, k; cin >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> l[i];
    
}