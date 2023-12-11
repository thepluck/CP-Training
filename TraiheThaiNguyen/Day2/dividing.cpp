#include <bits/stdc++.h>
using namespace std;

#define popcnt __builtin_popcount

int cnt[256];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; string s; cin >> n >> s;
    for (char c : s) cnt[c]++;
    vector <int> odd;
    for (char c = '0'; c <= '9'; c++)
        if (cnt[c] & 1)
            odd.push_back(c - '0');
    if (odd.empty()){
        cout << "0\n"; return 0;
    }
    int sz = odd.size(), res = INT_MAX;
    sort(odd.begin(), odd.end());
    vector <int> dgt = odd;
    sort(dgt.begin(), dgt.end());
    do {
        if (dgt[0] == 0 || dgt[sz / 2] == 0) continue;
        int x = 0, y = 0;
        for (int i = 0; i < sz / 2; i++)
            x = x * 10 + dgt[i];
        for (int i = sz / 2; i < sz; i++)
            y = y * 10 + dgt[i];
        res = min(res, abs(x - y));
    }
    while (next_permutation(dgt.begin(), dgt.end()));
    for (int d = 0; d <= 9; d++){
        if (cnt[d + '0'] < 2) continue; dgt = odd;
        dgt.push_back(d); dgt.push_back(d);
        sort(dgt.begin(), dgt.end()); sz = dgt.size();
        do {
            if (dgt[0] == 0 || dgt[sz / 2] == 0) continue;
            int x = 0, y = 0;
            for (int i = 0; i < sz / 2; i++)
                x = x * 10 + dgt[i];
            for (int i = sz / 2; i < sz; i++)
                y = y * 10 + dgt[i];
            res = min(res, abs(x - y));
        }
        while (next_permutation(dgt.begin(), dgt.end()));
    }
    cout << res << '\n'; 
}