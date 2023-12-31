#include <bits/stdc++.h>
using namespace std;

namespace suffixarray{
    static const int N = 1e6 + 5;
    int cnt[N], sa[N], x[N], y[N], lcp[N];
    int* build_sa(string s){
        s += char(1); int n = s.size();
        for (int i = 0; i < n; i++) cnt[s[i]]++;
        for (int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; ~i; i--) sa[--cnt[s[i]]] = i;
        for (int i = 1; i < n; i++){
            x[sa[i]] = x[sa[i - 1]]; 
            if (s[sa[i]] != s[sa[i - 1]]) x[sa[i]]++;
        }
        for (int j = 1; j < n; j <<= 1){
            fill_n(cnt, n, 0);
            for (int i = 0; i < n; i++) cnt[x[i]]++;
            for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; ~i; i--){
                int prev = (sa[i] - j + n) % n;
                y[--cnt[x[prev]]] = prev;
            } 
            swap(sa, y); y[sa[0]] = 0;
            for (int i = 1; i < n; i++){
                y[sa[i]] = y[sa[i - 1]];
                if (x[sa[i]] != x[sa[i - 1]]) y[sa[i]]++;
                else {
                    int p = sa[i] + j, q = sa[i - 1] + j;
                    if (x[p % n] != x[q % n]) y[sa[i]]++;
                }
            }
            swap(x, y);
        }
        rotate(sa, sa + 1, sa + n); n--;
        return sa;
    }
    int* build_lcp(string s){
        int n = s.size();
        for (int i = 0; i < n; i++) x[sa[i]] = i;
        for (int i = 0, k = 0; i < n; i++, k ? k-- : 0){
            if (x[i] == n - 1){
                k = 0; lcp[x[i]] = 0; continue;
            }
            int j = sa[x[i] + 1];
            while (max(i, j) + k < n && s[i + k] == s[j + k]) k++;
            lcp[x[i]] = k;
        }
        return lcp;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    string x = s + char(1) + t;
    using namespace suffixarray;
    build_sa(x); build_lcp(x);
    int res = 0;
    for (int i = 0; i < x.size(); i++){
        if (sa[i] < s.size() && sa[i + 1] > s.size())
            res = max(res, lcp[i]);
        if (sa[i] > s.size() && sa[i + 1] < s.size())
            res = max(res, lcp[i]);
    }
    cout << res << '\n';
}