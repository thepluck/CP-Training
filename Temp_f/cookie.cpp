#include <bits/stdc++.h>
using namespace std;

struct NumTrie{
    static const int N = 2e5 + 5;
    struct TNode{
        int cnt[2], child[2];
        TNode(){
            cnt[0] = cnt[1] = 0;
        }
    } Trie[N * 35];
    int cont = 0, sz = 0;
    NumTrie(){}
    bool insert(int x){
        int pt = 0; bool bit;
        for (int i = 31; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit] == 0){
                Trie[pt].cnt[bit] = 1;
                Trie[pt].child[bit] = ++cont;
            }
            else ++Trie[pt].cnt[bit];
            pt = Trie[pt].child[bit];
        }
        sz++; return true;
    }
    bool erase(int x){
        int pt = 0; bool bit;
        for (int i = 31; i >= 0; --i){
            bit = (x >> i) & 1;
            --Trie[pt].cnt[bit];
            pt = Trie[pt].child[bit];
        }
        sz--; return true;
    }
    int count(int x){
        int pt = 0, res = 0; bool bit;
        for (int i = 31; i >= 0; --i){
            bit = (x >> i) & 1;
            if (bit) res += Trie[pt].cnt[0];
            if (Trie[pt].cnt[bit] > 0)
                pt = Trie[pt].child[bit];
            else break;
        }
        return res;
    }
    int order(int k){
        int pt = 0, res = 0;
        for (int i = 31; i >= 0; --i){
            if (Trie[pt].cnt[0] >= k){
                res <<= 1; pt = Trie[pt].child[0];
            }
            else {
                res += res + 1; k-= Trie[pt].cnt[0];
                pt = Trie[pt].child[1];
            }
        }
        return res;
    }

    int size() const {
        return sz;
    }
} nt;

int main(){
    freopen("cookie.inp", "r", stdin);
    freopen("cookie.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    while (cin >> s){
        if (s == "#"){
            int x = nt.order(nt.size() / 2 + 1);
            cout << x << '\n'; nt.erase(x);
        }
        else {
            int x = stoi(s); nt.insert(x);
        }
    }
}
