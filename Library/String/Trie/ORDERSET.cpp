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
    int size = 0;
    NumTrie(){}
    bool insert(int x){
        int pt = 0; bool bit, flag = false;
        for (int i = 31; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit] == 0){
                flag = true; break;
            }
            pt = Trie[pt].child[bit];
        }
        if (!flag) return false; pt = 0;
        for (int i = 31; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit] == 0){
                Trie[pt].cnt[bit] = 1;
                Trie[pt].child[bit] = ++size;
            }
            else ++Trie[pt].cnt[bit];
            pt = Trie[pt].child[bit];
        }
        return true;
    }
    bool erase(int x){
        int pt = 0; bool bit, flag = true;
        for (int i = 31; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit] == 0){
                flag = false; break;
            }
            pt = Trie[pt].child[bit];
        }
        if (!flag) return false; pt = 0;
        for (int i = 31; i >= 0; --i){
            bit = (x >> i) & 1;
            --Trie[pt].cnt[bit];
            pt = Trie[pt].child[bit];
        }
        return true;
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
} NT;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); char cmd;
    int cnt = 0, n, off = 1e9, val; cin >> n;
    while (n--){
        cin >> cmd >> val;
        if (cmd == 'I') cnt += NT.insert(val + off);
        if (cmd == 'D') cnt -= NT.erase(val + off);
        if (cmd == 'K'){
            if (val > cnt) cout << "invalid\n";
            else cout << NT.order(val) - off << '\n';
        }
        if (cmd == 'C') cout << NT.count(val + off) << '\n';
    }
}