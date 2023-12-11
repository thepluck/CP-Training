
// Problem : E. You Are Given Some Strings...
// Contest : Codeforces - Educational Codeforces Round 70 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1202/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

struct state {
    int nxt[26], link, cnt;
    
    state(): link(0), cnt(0) {
        memset(nxt, 0, sizeof nxt);
    }
};

vector <state> tree;

int& nxt(int u, char c){
    return tree[u].nxt[c - 'a'];
}

int& link(int u){
    return tree[u].link;
}

int& cnt(int u){
    return tree[u].cnt;
}

void insert(const string &s) {
    int pt = 0;
    for (char c : s){
        if (!nxt(pt, c)){
            nxt(pt, c) = tree.size();
            tree.emplace_back();
        }
        pt = nxt(pt, c);
    }
    cnt(pt)++;
}

void automata() {
    queue <int> q; q.push(0);
    while (!q.empty()){
        int u = q.front(); q.pop();
        cnt(u) += cnt(link(u));
        for (char c = 'a'; c <= 'z'; c++){
            int v = nxt(u, c);
            if (v){
                link(v) = u ? nxt(link(u), c) : 0;
                q.push(v); nxt(u, c) = v;
            }
            else nxt(u, c) = nxt(link(u), c);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string t; cin >> t;
    int m = t.size();
    vector <int> pre(m), suf(m);
    int k; cin >> k;
    vector <string> x(k);
    tree.emplace_back();
    for (string &s : x) {
        cin >> s; insert(s);
    }
    automata(); int pt = 0;
    for (int i = 0; i < m; i++) {
        pt = nxt(pt, t[i]);
        pre[i] += cnt(pt);
    }
    tree.clear();
    tree.emplace_back();
    for (string &s : x) {
        reverse(s.begin(), s.end());
        insert(s);
    }
    automata(); pt = 0;
    reverse(t.begin(), t.end());
    for (int i = 0; i < m; i++) {
        pt = nxt(pt, t[i]);
        suf[i] += cnt(pt);
    }
    reverse(suf.begin(), suf.end());
    long long res = 0;
    for (int i = 1; i < m; i++)
        res += 1ll * pre[i - 1] * suf[i];
    cout << res << '\n';
}