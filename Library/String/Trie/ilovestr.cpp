#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5; int id[N];
string seq = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

class trie{
public:
    int nxt[N][128], aut[N][128], link[N], near[N], sz;
    bool leaf[N], ok[N]; int dep[N];

    void clear(){
        for (int i = 0; i <= sz; i++){
            link[i] = near[i] = ok[i] = leaf[i] = 0;
            for (int c = 0; c < 60; c++)
                nxt[i][c] = aut[i][c] = 0;
        }
        sz = 0;
    }
 
    void insert(const string &s, int i){
        int pt = 0;
        for (char c : s){
            int tmp = c <= 'z' ? c - 'a' : c - 'a' + 26;
            if (!nxt[pt][tmp]) nxt[pt][tmp] = ++sz;
            dep[nxt[pt][tmp]] = dep[pt] + 1;
            pt = nxt[pt][tmp];
        }
        leaf[pt] = 1; id[i] = pt;
    }
 
 
    void build_link(){
        queue <int> q; q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (int c = 0; c < 60; c++){
                if (nxt[u][c]){
                    link[nxt[u][c]] = u ? aut[link[u]][c] : 0;
                    q.push(nxt[u][c]); aut[u][c] = nxt[u][c];
                }
                else aut[u][c] = aut[link[u]][c];
            }
        }
    }
 
    void solve(const string &s){
        int pt = 0;
        for (char c : s){
            int tmp = c <= 'z' ? c - 'a' : c - 'a' + 26;
            pt = aut[pt][tmp]; ok[pt] = true;
        }
        vector <int> order;
        for (int i = 0; i <= sz; i++) order.push_back(i);
        sort(order.begin(), order.end(),
        [&](int p, int q){
            return dep[p] > dep[q];
        });
        for (int x : order) ok[link[x]] |= ok[x];
    }
} tt;

void solve(){
    tt.clear();
    string s, t; cin >> s; int q; cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> t; tt.insert(t, i);
    }
    tt.build_link(); tt.solve(s);
    for (int i = 1; i <= q; i++)
        cout << (tt.ok[id[i]] ? "y\n" : "n\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}