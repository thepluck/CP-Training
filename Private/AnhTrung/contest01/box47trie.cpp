#include <bits/stdc++.h>
using namespace std;

struct NumTrie{
    #define fi first
    #define se second
    using ll = long long;
    static const int N = 2e5 + 5;
    static const int offset = 1e9;
    struct TNode{
        int cnt[2], child[2]; ll sum[2];
        TNode(){
            cnt[0] = cnt[1] = 0;
            sum[0] = sum[1] = 0ll;
        }
    } Trie[N * 31];
    unordered_map <int, int> mp;
    int size = 0; NumTrie(){}
    bool insert(int x){
        int pt = 0; bool bit; ++mp[x];
        for (int i = 31; i >= 0; --i){
            bit = (x + offset) >> i & 1;
            if (Trie[pt].cnt[bit] == 0){
                Trie[pt].cnt[bit] = 1;
                Trie[pt].child[bit] = ++size;
                Trie[pt].sum[bit] = x;
            }
            else {
                ++Trie[pt].cnt[bit];
                Trie[pt].sum[bit] += x;
            }
            pt = Trie[pt].child[bit];
        }
        return true;
    }
    bool erase(int x){
        auto it = mp.find(x);
        if (it == mp.end() || it->se == 0) 
            return false;
        int pt = 0; bool bit; --(it->se);
        for (int i = 31; i >= 0; --i){
            bit = (x + offset) >> i & 1;
            --Trie[pt].cnt[bit];
            Trie[pt].sum[bit] -= x;
            pt = Trie[pt].child[bit];
        }
        return true;
    }
    int count(int x){
        int pt = 0, res = 0; bool bit;
        for (int i = 31; i >= 0; --i){
            bit = (x + offset) >> i & 1;
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
        return res - offset;
    }
    ll sum(int x){
        int pt = 0; ll res = 0; bool bit;
        for (int i = 31; i >= 0; --i){
            bit = (x + offset) >> i & 1;
            if (bit) res += Trie[pt].sum[0];
            if (Trie[pt].cnt[bit] > 0)
                pt = Trie[pt].child[bit];
            else break;
        }
        return res;
    }
} NT;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cnt = 0, n; cin >> n;
    while (n--){
        int cmd; cin >> cmd;
        if (cmd == 1){
            int x; cin >> x; cnt += NT.insert(x);
        }
        if (cmd == 2){
            int x; cin >> x; cnt += NT.erase(x);
        }
        if (cmd == 3){
            int k; cin >> k; cout << NT.order(k) << '\n';
        }
        if (cmd == 4){
            int a, b; cin >> a >> b;
            cout << NT.sum(b + 1) - NT.sum(a) << '\n';
        }
    }
}