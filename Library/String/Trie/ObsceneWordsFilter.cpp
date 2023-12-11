#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4; set <char> ss;

class trie{
private:
    map <char, int> nxt[N], aut[N];
    int link[N], sz, near[N], len[N]; bitset <N> leaf;

public:
    trie(): sz(0){
        memset(link, 0, sizeof link);
    }

    void insert(const string &s){
        int pt = 0;
        for (char c : s){
            if (!nxt[pt].count(c)) nxt[pt][c] = ++sz;
            pt = nxt[pt][c];
        }
        leaf[pt] = 1; len[pt] = s.size();
    }

    void build_link(){
        queue <int> q; q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (char c : ss){
                if (nxt[u].count(c)){
                    link[nxt[u][c]] = u ? aut[link[u]][c] : 0;
                    q.push(nxt[u][c]); aut[u][c] = nxt[u][c];
                }
                else aut[u][c] = aut[link[u]][c];
            }
        }
        q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (char c : ss)
                if (nxt[u].count(c)){
                    if (leaf[nxt[u][c]]) near[nxt[u][c]] = nxt[u][c];
                    else near[nxt[u][c]] = near[link[nxt[u][c]]];
                    q.push(nxt[u][c]);
                }
        }
    }

    int is_cover(const string &s){
        int pt = 0;
        for (int i = 0; i < s.size(); i++){
            pt = aut[pt].count(s[i]) ? aut[pt][s[i]] : 0;
            if (leaf[near[pt]]) return i - len[near[pt]] + 1;
        }
        return -1;
    }
} tt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n; string s; getline(cin, s);
    while (n--){
        getline(cin, s); tt.insert(s);
        for (char c : s) ss.insert(c);
    }
    cin >> m; tt.build_link(); getline(cin, s);
    for (int i = 1; i <= m; i++){
        getline(cin, s); int tmp = tt.is_cover(s);
        if (~tmp) return cout << i << ' ' << tmp + 1 << '\n', 0;
    }
    cout << "Passed\n";
}