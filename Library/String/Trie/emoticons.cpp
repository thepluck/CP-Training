#include <bits/stdc++.h>
using namespace std;
 
const int N = 2000;
 
class trie{
private:
    int nxt[N][128], aut[N][128], link[N], near[N], sz; bool leaf[N];
 
public:
    void init(){
        for (int i = 0; i <= sz; i++){
            link[i] = near[i] = leaf[i] = 0;
            for (int c = 0; c < 128; c++) nxt[i][c] = aut[i][c] = 0;
        }
        sz = 0;
    }
 
    void insert(const string &s){
        int pt = 0;
        for (char c : s){
            if (!nxt[pt][c]) nxt[pt][c] = ++sz; pt = nxt[pt][c];
        }
        leaf[pt] = 1;
    }
 
 
    void build_link(){
        queue <int> q; q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (int c = 0; c < 128; c++){
                if (nxt[u][c]){
                    link[nxt[u][c]] = u ? aut[link[u]][c] : 0;
                    q.push(nxt[u][c]); aut[u][c] = nxt[u][c];
                }
                else aut[u][c] = aut[link[u]][c];
            }
        }
        q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (int c = 0; c < 128; c++)
                if (nxt[u][c]){
                    if (leaf[nxt[u][c]]) near[nxt[u][c]] = nxt[u][c];
                    else near[nxt[u][c]] = near[link[nxt[u][c]]];
                    q.push(nxt[u][c]);
                }
        }
    }
 
    int solve(const string &s){
        int pt = 0, res = 0;
        for (char c : s){
            pt = aut[pt][c]; if (leaf[near[pt]]) pt = 0, res++;
        }
        return res;
    }
} tt;
 
bool solve(){
    int n, m; cin >> n >> m;
    if (n + m == 0) return false; tt.init();
    string s; while (n--){cin >> s; tt.insert(s);}
    tt.build_link(); int res = 0; cin.ignore();
    while(m--){getline(cin, s); res += tt.solve(s);}
    cout << res << '\n'; return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(solve());
}