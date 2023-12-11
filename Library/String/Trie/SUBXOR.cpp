/// given an array a and integer k
/// count number of subarrays such as xor of them < k
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct NumTrie{
    struct TNode{
        int cnt[2], ch[2];
        TNode(){
            cnt[0] = cnt[1] = 0;
        }
    };
    vector <TNode> Trie;
    NumTrie(){
        Trie.push_back(TNode());
    }
    void clear(){
        Trie.clear(); Trie.push_back(TNode());
    }
    bool insert(const int &x){
        int pt = 0; bool bit, flag = false;
        for (int i = 30; i >= 0; --i){
            bit = (x >> i) & 1;
            if (Trie[pt].cnt[bit] == 0){
                Trie[pt].cnt[bit] = 1;
                Trie[pt].ch[bit] = Trie.size();
                Trie.push_back(TNode());
                flag = true;
            }
            else ++Trie[pt].cnt[bit];
            pt = Trie[pt].ch[bit];
        }
        return flag;
    }
    int count(const int &x, const int &k){
        int pt = 0, res = 0; bool bit;
        for (int i = 30; i >= 0; --i){
            bit = (x >> i) & 1;
            if ((k >> i) & 1){
                res += Trie[pt].cnt[bit];
                if (Trie[pt].cnt[bit ^ 1] > 0)
                    pt = Trie[pt].ch[bit ^ 1];
                else break;
            }
            else {
                if (Trie[pt].cnt[bit] > 0)
                    pt = Trie[pt].ch[bit];
                else break;
            }
        }
        return res;
    }
} T;

void solve(){
    int n, k; cin >> n >> k;
    int cur = 0, x; ll ans = 0;
    T.insert(0);
    while (n--){
        cin >> x; cur ^= x;
        ans += T.count(cur, k);
        T.insert(cur);
    }
    T.clear(); cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}