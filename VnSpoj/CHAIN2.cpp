#include <bits/stdc++.h>
using namespace std;

struct Trie{
    static const int N = 2.5e5 + 5; 
    struct TNode{
        int child[26]; bool has;
        TNode(): has(false){
            memset(child, -1, sizeof child);
        }
        int& operator [] (const int &x){
            return child[x];
        }
        int& operator [] (const char &c){
            return child[c - 'a'];
        }
    } Tree[N * 26]; 
    int size; Trie(): size(0){}
    bool insert(const string &s){
        int pt = 0; bool flag = false;
        for (auto c : s){
            if (Tree[pt][c] == -1){
                Tree[pt][c] = ++size; 
                flag = true;
            }
            pt = Tree[pt][c];
        }
        Tree[pt].has = true;
        return flag;
    }
    int chain(int pt, int cnt){
        cnt += Tree[pt].has; int res(cnt);
        for (auto c : Tree[pt].child)
            if (c != -1) 
                res = max(res, chain(c, cnt));
        return res;
    }
} T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; string s;
    while (n--){
        cin >> s; T.insert(s);
    }
    cout << T.chain(0, 0) << '\n';
}