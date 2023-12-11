// Problem: C. Big Secret
// Contest: Codeforces - VK Cup 2018 - Round 3
// URL: https://codeforces.com/contest/925/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int LG = 60;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector <long long> p[LG], a;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        for (int j = LG - 1; ~j; j--)
            if (x >> j & 1) {
                p[j].push_back(x);
                break;
            }
    }
    long long s = 0; 
    for (int i = 0; i < n; i++) {
        long long x = -1;
        for (int j = 0; j < LG; j++)
            if (!(s >> j & 1)
            && !p[j].empty()) {
                x = p[j].back();
                p[j].pop_back();
                break;
            }
        if (x < 0)
            return cout << "No\n", 0;
        a.push_back(x); s ^= x;
    }
    cout << "Yes\n";
    for (long long x : a)
        cout << x << ' ';
}