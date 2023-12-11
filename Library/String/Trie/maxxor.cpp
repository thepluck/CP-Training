#include <bits/stdc++.h>
using namespace std;

struct NumTrie{
    struct TNode{
        int cnt[2], child[2];
        TNode(){
            cnt[0] = cnt[1] = 0;
        }
    };
    vector <TNode> Trie;
    NumTrie(){
        Trie.push_back(TNode());
    }
    bool insert(const int &x){
        int pt = 0; bool bit, flag = false;
        for (int i = 30; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit] == 0){
                Trie[pt].cnt[bit] = 1;
                Trie.push_back(TNode());
                Trie[pt].child[bit] = Trie.size() - 1;
                flag = true;
            }
            else ++Trie[pt].cnt[bit];
            pt = Trie[pt].child[bit];
        }
        return flag;
    }
    bool erase(const int &x){
        int pt = 0; bool bit;
        for (int i = 30; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit] == 0) return false;
            --Trie[pt].cnt[bit];
            pt = Trie[pt].child[bit];
        }
        return true;
    }
    int xormax(const int &x){
        int pt = 0, res = 0; bool bit;
        for (int i = 30; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit ^ 1] > 0) {
                pt = Trie[pt].child[bit ^ 1];
                if (bit ^ 1) res ^= 1 << i;
            }
            else {
                pt = Trie[pt].child[bit];
                if (bit) res ^= 1 << i;
            }
        }
        return res;
    }
} T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    char cmd; int val;
    T.insert(0);
    while (q--){
        cin >> cmd >> val;
        if (cmd == '+') T.insert(val);
        if (cmd == '-') T.erase(val);
        if (cmd == '?') cout << (T.xormax(val) ^ val) << '\n';
    }
}