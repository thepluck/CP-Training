#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

class trie{
private:
    class node{
    public:
        int nxt[26], cnt;

        node(): cnt(0){
            memset(nxt, 0, sizeof nxt);
        }

        int& operator [] (const int &p){
            return nxt[p];
        }
    };

    node data[N]; int sz;
public:
    trie(): sz(0){}

    bool insert(const string &s){
        int pt = 0; bool flag = false;
        for (char c : s){
            if (!data[pt][c - 'a']){
                data[pt][c - 'a'] = ++sz;
                flag = true;
            }
            pt = data[pt][c - 'a'];
            data[pt].cnt++;
        }
        return flag;
    }

    int cnt_pref(const string &s){
        int pt = 0;
        for (char c : s){
            if (!data[pt][c - 'a'])
                return 0;
            pt = data[pt][c - 'a'];
        }
        return data[pt].cnt;
    }
} tt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    string s;
    while (n--){
        cin >> s; tt.insert(s);
    }
    while (q--){
        cin >> s;
        cout << tt.cnt_pref(s) << '\n';
    }
}