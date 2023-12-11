#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector <int> s;
    vector <int> res[20];
    for (int i = 0; i < n; i++)
        s.push_back(i > n - m);
    int cnt = 0;
    do {
        for (int i = 0; i < n; i++)
            if (!s[i]) res[i].push_back(cnt);
        cnt++;
    }
    while (next_permutation(s.begin(), s.end()));
    for (int i = 0; i < n; i++){
        for (int x : res[i]) cout << x << ' ';
        cout << '\n';
    }
}